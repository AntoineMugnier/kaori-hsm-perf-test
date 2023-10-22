#!/bin/bash
# This script builds the static lib. Must be run from its own dirctory

# Create Build dir in which will be generated the Makefiles
mkdir -p build

cd build

# Generate Makefiles
cmake ../ -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=gcc-arm-none-eabi.cmake -DTOOLCHAIN_BIN_DIR=/opt/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin

# Build project
make
