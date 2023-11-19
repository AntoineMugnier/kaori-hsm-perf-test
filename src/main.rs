// Copyright © 2023 cortex-m-microclock. All rights reserved.
// SPDX-License-Identifier: Apache-2.0 OR MIT

// This example has been tested on a a STM32F103 blue pill (STM32F103C8T6 MCU) target with Ubuntu
// 22.0.4.  
// The following code initializes the MCU and triggers a loop which repeatidly creates a 1 second delay and sends its measure to the host through RTT tracing.
// 
// ##  How to run it ?
// - You must have installed `probe-run` and the `thumbv7m-none-eabi` toolchain . 
//      - Follow instructions [here](https://crates.io/crates/probe-run) to install probe-run.
//      - For installing the toolchain : `cargo install thumbv7m-none-eabi` 
// - Connect a ST-LINK probe to the blue pill with SWCLK, SWDIO, RST, GND, and 3V3 lines. Be sure
// your udev rules are well configured on Linux.
// - run `DEFMT_LOG=trace cargo run --example stm32f1` at the root of the project. Microcontroller
// flashing should occur and you should see a new trace emitted every second by the microcontroller
// on your console.
//

#![no_main]
#![no_std]
mod basic_hsm;
use kaori_hsm::StateMachine;
use basic_hsm::BasicStateMachine;
use cortex_m_rt::{entry, exception};
use defmt::println;
use stm32f1::stm32f103;
use cortex_m::peripheral::syst;
use basic_hsm::BasicEvt;
use defmt_rtt as _; // global logger
use panic_probe as _;
use core::ffi::CStr;
const SYSCLK_FREQ_HZ : u32 = 8_000_000;

// Aliases for the library generic types 
type Microclock = cortex_m_microclock::CYCCNTClock<SYSCLK_FREQ_HZ>;

include!(concat!(env!("OUT_DIR"), "/wrapper.rs"));

macro_rules! print_time {
    ($fn_call: expr, $prefix_str: expr) => {
        {
            let init_inst = Microclock::now();
            let ret = $fn_call;
            let end_inst = Microclock::now();
            let elapsed_time = end_inst - init_inst;
            println!("{} took {} µs", $prefix_str, elapsed_time.to_micros());
            ret 
        }
    };
}

#[entry]
fn main() -> ! {
       
    let cp = cortex_m::Peripherals::take().unwrap();
    let mut p = stm32f103::Peripherals::take().unwrap();

    //Configure clock tree
    let rcc = &mut p.RCC;

    // Set 8mhz HSE as direct SYSCLK source    
    rcc.cr.write(|w| w
        .hseon().set_bit()
    );

    // Wait for clock to stabilize
    while !rcc.cr.read().hserdy().bit() {/*NOP*/ }

    // Configure Systick
    // Systick is fed by SYSCLK (8MHz) divided by 8 (No division by AHB Prescaler).
    let mut systick = cp.SYST;
    systick.set_clock_source(syst::SystClkSource::Core);
    systick.set_reload(999);
    systick.clear_current();
    systick.enable_counter();
    
    //Setup CYCCNT clock
    let mut dcb = cp.DCB;
    let dwt = cp.DWT;
    Microclock::init(&mut dcb, dwt);
    
    // Delayed enabling of systick IRQs as `Microclock::update()` should not be triggered before call to `Microclock::init()`
    systick.enable_interrupt();

    loop {
        let basic_state_machine = BasicStateMachine::new();

        let mut kaori_hsm = StateMachine::from(basic_state_machine);

        println!("Init state machine");
        print_time!(kaori_hsm.init(), "Kaori HSM init");
        unsafe{
            let debug_buff = print_time!(init_hsm(), "QPCPP HSM init");
            let debug_buff = CStr::from_ptr(debug_buff as *const i8);
            defmt::debug!("{}", debug_buff.to_str().unwrap());
        }
        
        let evt_a: (BasicEvt, unsafe extern "C" fn() -> *const u8) = (BasicEvt::A, dispatch_evt_A);
        let evt_b: (BasicEvt, unsafe extern "C" fn() -> *const u8) = (BasicEvt::B, dispatch_evt_B);
        let evt_c: (BasicEvt, unsafe extern "C" fn() -> *const u8) = (BasicEvt::C, dispatch_evt_C);
        let evt_d: (BasicEvt, unsafe extern "C" fn() -> *const u8) = (BasicEvt::D, dispatch_evt_D);

        let evt_list = [
            evt_a, evt_b, evt_c, evt_d, evt_b, evt_b
        ];

        for evt in evt_list {
            println!("\r\nDispatching evt {:?}", evt.0);
            print_time!(kaori_hsm.dispatch(&evt.0), "Kaori HSM evt dispatch");

            unsafe{
                let debug_buff = print_time!(evt.1(), "QPCPP HSM evt dispatch");
                let debug_buff =  CStr::from_ptr(debug_buff as *const i8);
                defmt::debug!("{}", debug_buff.to_str().unwrap());
            }
        }

        loop {}
     
    }
}

#[exception]
fn SysTick(){
    Microclock::update();
}
