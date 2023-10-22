#!/bin/bash
#
mkdir -p build
cd build

# setup cmake
cmake ../ -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=gcc-arm-none-eabi.cmake -DTOOLCHAIN_BIN_DIR=/opt/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin
make
