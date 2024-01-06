set(CMAKE_SYSTEM_NAME               Generic)
set(CMAKE_SYSTEM_PROCESSOR          arm)

# Some default GCC settings
# arm-none-eabi- must be part of path environment
set(TOOL_CHAIN_PREFIX                arm-none-eabi)
set(COMPILER_OPTIONS "-mthumb -mcpu=cortex-m3 -mlittle-endian -mthumb-interwork -Os ")

SET(CMAKE_C_FLAGS "${COMPILER_OPTIONS} -lm -lc -lnosys --specs=nosys.specs -ffunction-sections -fdata-sections" CACHE INTERNAL "c compiler flags")
SET(CMAKE_CXX_FLAGS "${COMPILER_OPTIONS} -lm -lc -lnosys --specs=nosys.specs -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions " CACHE INTERNAL "cxx compiler flags")
SET(CMAKE_ASM_FLAGS "${COMPILER_OPTIONS}" CACHE INTERNAL "asm compiler flags")

SET(CMAKE_EXE_LINKER_FLAGS "${COMPILER_OPTIONS} -Wl,-Map=linker.map -Wl,-cref -Wl,--gc-sections" CACHE INTERNAL "exe link flags")

# Define compiler settings
SET(CMAKE_AR               ${TOOL_CHAIN_PREFIX}-gcc-ar)
SET(CMAKE_RANLIB           ${TOOL_CHAIN_PREFIX}-gcc-ranlib)
SET(CMAKE_LD               ${TOOL_CHAIN_PREFIX}-ld)
set(CMAKE_C_COMPILER       ${TOOL_CHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER     ${TOOL_CHAIN_PREFIX}-g++)
set(CMAKE_ASM_COMPILER     ${TOOL_CHAIN_PREFIX}-as)
set(CMAKE_OBJCOPY     	   ${TOOL_CHAIN_PREFIX}-objcopy CACHE INTERNAL "objcopy command")
set(CMAKE_OBJDUMP     	   ${TOOL_CHAIN_PREFIX}-objdump CACHE INTERNAL "objdump command")
set(CMAKE_GDB              ${TOOL_CHAIN_PREFIX}-gdb)
set(CMAKE_SIZE             ${TOOL_CHAIN_PREFIX}-size)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
