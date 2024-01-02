#!/bin/bash
# This script builds the static lib. Must be run from its own dirctory

# Create Build dir in which will be generated the Makefiles
mkdir -p build

cd build

# Generate Makefiles
cmake ../ -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=gcc-arm-none-eabi.cmake

# Build project
make
