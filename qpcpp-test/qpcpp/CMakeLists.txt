add_library(qpcpp INTERFACE)
target_sources(qpcpp INTERFACE ./qpcpp/src/qf/qep_hsm.cpp)
target_include_directories(qpcpp INTERFACE ./qpcpp/include/ ./qpcpp/ports/qep-only/)
