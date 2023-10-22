cmake_minimum_required(VERSION 3.2)

project(kaori-hsm-perf-test LANGUAGES C CXX ASM)

add_library(qpcpp-tst STATIC tst.c)
