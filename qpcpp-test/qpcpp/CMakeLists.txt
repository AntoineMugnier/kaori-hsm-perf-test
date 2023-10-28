add_library(qpcpp INTERFACE)
target_sources(qpcpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/qpcpp/src/qf/qep_hsm.cpp)
target_include_directories(qpcpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/qpcpp/include/ ${CMAKE_CURRENT_SOURCE_DIR}/qpcpp/ports/qep-only/)
