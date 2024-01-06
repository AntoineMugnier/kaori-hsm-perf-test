# Purpose of this test 
This test aims to test the performance of the kaori_hsm library in comparaison to the QEP library developped by Miro Samek.
QEP performances have been taken as a reference as it is a library which has long proven to be efficient and robust for developing
hierarhical state machines in C++.
The test is mostly written in Rust. Only QEP along with some interface code are precompiled in C++ and called from the Rust code.

# Required Hardware
The test has been compiled for the stm32f103c8t6 microcontroller. The board used for the test is a stm32f103 blue pill and the
debugger is a STLINK-V2 with Serial Wire debug Data Input/Output (SWDIO), Serial Wire Clock (SWCLK), 3V3 and GND pins connected.
RTT is used to allow the probe and the host to communicate. RTT has the advantage of using the debug port for communication
and thus does not need extra pins.

# Commands index
## Run the test for performance-only
Faster mode, nothing else than the performance result is reported to host. 
```shell
    DEMFT_LOG=info cargo run --release
```
## Run the test for debug
Every action taken by the state machine will be notified to host. No performance can be evaluated in this mode.
```shell
    DEMFT_LOG=debug cargo run 
```

## Diagram of the state machine of the test
![intro_hsm](https://github.com/AntoineMugnier/kaori-hsm-perf-test/blob/assets/kaori-hsm-perf-test.png?raw=true)
