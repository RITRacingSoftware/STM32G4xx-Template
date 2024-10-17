# Required header
cmake_minimum_required(VERSION 3.0)

# Setup toolchain
set(CMAKE_TOOLCHAIN_FILE "CMakeToolchain.txt")

project(RITRacing-temp
	VERSION 32
	LANGUAGES C CXX ASM
)

set(EXECUTABLE_NAME "temp")

set(CUBE_DIR "lib/STM32CubeG4")

# Collect sources
file(GLOB_RECURSE STARTUP_SOURCES src/*.s)
file(GLOB_RECURSE APP_SOURCES src/*.c)
file(GLOB_RECURSE CUBE_SOURCES ${CUBE_DIR}/Drivers/STM32G4xx_HAL_Driver/Src/*.c)
list(FILTER CUBE_SOURCES EXCLUDE REGEX "template")

set(EXECUTABLE_ELF ${EXECUTABLE_NAME}.elf)
set(EXECUTABLE_BIN ${EXECUTABLE_NAME}.bin)
set(EXECUTABLE_MAP ${EXECUTABLE_NAME}.map)
add_executable(${EXECUTABLE_ELF} ${STARTUP_SOURCES} ${APP_SOURCES} ${CUBE_SOURCES})

target_compile_options(${EXECUTABLE_ELF} PRIVATE
	-mcpu=cortex-m0
	-march=armv6-m
	-fdata-sections
	-ffunction-sections
	-Wall
	-g
)

target_compile_definitions(${EXECUTABLE_ELF} PRIVATE
	-DUSE_HAL_DRIVER
	-DSTM32G473xx
	-DSTM32G47373
)

target_include_directories(${EXECUTABLE_ELF} PRIVATE
	src
	${CUBE_DIR}/Drivers/STM32G4xx_HAL_Driver/Inc
	${CUBE_DIR}/Drivers/CMSIS/Device/ST/STM32G4xx/Include
	${CUBE_DIR}/Drivers/CMSIS/Include
)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32G473RETx_FLASH.ld)

target_link_options(${EXECUTABLE_ELF} PRIVATE
	-mcpu=cortex-m0
	-march=armv6-m
	-T${LINKER_SCRIPT}
	-lnosys
	-specs=nano.specs
	-Wl,-Map=${EXECUTABLE_MAP},--cref
	-Wl,--gc-sections
	-g
)

add_link_options(
	-specs=nano.specs
)

add_custom_command(TARGET ${EXECUTABLE_ELF}
	POST_BUILD
	COMMAND ${TOOLCHAIN_PREFIX}-objcopy -O binary ${EXECUTABLE_ELF} ${EXECUTABLE_BIN}
)
