//! This build script copies the `memory.x` file from the crate root into
//! a directory where the linker can always find it at build time.
//! For many projects this is optional, as the linker always searches the
//! project root directory -- wherever `Cargo.toml` is. However, if you
//! are using a workspace or have a more complicated build setup, this
//! build script becomes required. Additionally, by requesting that
//! Cargo re-run the build script whenever `memory.x` is changed,
//! updating `memory.x` ensures a rebuild of the application with the
//! new memory settings.
//!
//! The build script also sets the linker flags to tell it which link script to use.

use std::env;
use std::fs::File;
use std::io::Write;
use std::path::PathBuf;
use std::process::Command;

fn main() {
    // Put `memory.x` in our output directory and ensure it's
    // on the linker search path.
    let out = &PathBuf::from(env::var_os("OUT_DIR").unwrap());
    File::create(out.join("memory.x"))
        .unwrap()
        .write_all(include_bytes!("memory.x"))
        .unwrap();
    println!("cargo:rustc-link-search={}", out.display());

    // By default, Cargo will re-run a build script whenever
    // any file in the project changes. By specifying `memory.x`
    // here, we ensure the build script is only re-run when
    // `memory.x` is changed.
    println!("cargo:rerun-if-changed=memory.x");

    // Specify linker arguments.

    // `--nmagic` is required if memory section addresses are not aligned to 0x10000,
    // for example the FLASH and RAM sections in your `memory.x`.
    // See https://github.com/rust-embedded/cortex-m-quickstart/pull/95
    println!("cargo:rustc-link-arg=--nmagic");

    // Set the linker script to the one provided by cortex-m-rt.
    println!("cargo:rustc-link-arg=-Tlink.x");

    println!("cargo:rustc-linker=flip-link");
    println!("cargo:rustc-link-arg=-Tdefmt.x");

    // Compile qpcpp-test external lib

    let cmd_output = Command::new("bash")
        .arg("build.sh")
        .current_dir("qpcpp-test")
        .env(
            "DEFMT_LOG",
            std::env::var("DEFMT_LOG").unwrap_or_else(|_| String::from("")),
        )
        .output()
        .expect("Cannot execute qpcpp-test/build.sh");
    let status = cmd_output.status;
    if !status.success() {
        panic!(
            "Cannot compile qpcpp-test: \r\n{}",
            String::from_utf8(cmd_output.stderr).unwrap()
        )
    }

    println!("cargo:rustc-link-search=native=qpcpp-test/build");
    println!("cargo:rustc-link-lib=static=qpcpp-tst");

    // This build.rs script is rerun if any source or header of the lib changes
    println!("cargo:rerun-if-changed=qpcpp-test");

    let bindings = bindgen::Builder::default()
        // The input header we would like to generate
        // bindings for.
        .header("qpcpp-test/wrapper.hpp")
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .ctypes_prefix("cty")
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate wrapper.rs");

    // Write the bindings to the $OUT_DIR/wrapper.rs file.
    bindings
        .write_to_file(out.join("wrapper.rs"))
        .expect("Couldn't write wrapper.rs!");
}
