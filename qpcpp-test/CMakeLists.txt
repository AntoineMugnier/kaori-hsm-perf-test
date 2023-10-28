cmake_minimum_required(VERSION 3.2)

project(kaori-hsm-perf-test LANGUAGES C CXX ASM)
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_C_STANDARD                11)
add_library(qpcpp-tst STATIC basic_hsm_qpcpp.cpp)
add_subdirectory(./qpcpp/)
target_link_libraries(qpcpp-tst qpcpp)
