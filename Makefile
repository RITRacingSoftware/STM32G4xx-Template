PROJECT_NAME := ssdb
PROJECT_VERSION := f32

# Build info
BUILD_DIR := build
STM32_BUILD_DIR := $(BUILD_DIR)/stm32

# Cross-compilation tooling
STM32_PREFIX := arm-none-eabi
STM32_CC := $(STM32_PREFIX)-gcc
STM32_ASM := $(STM32_PREFIX)-gcc
STM32_LD := $(STM32_PREFIX)-gcc
STM32_GDB := $(STM32_PREFIX)-gdb
STM32_OBJCOPY := $(STM32_PREFIX)-objcopy
STM32_OBJDUMP := $(STM32_PREFIX)-objdump

# Cross-compilation options
STM32_COMMON_FLAGS := -mcpu=cortex-m4 -D USE_HAL_DRIVER -D STM32G473xx
STM32_CC_FLAGS := $(STM32_COMMON_FLAGS) -ffreestanding -ffunction-sections -fdata-sections -Wall -Wextra -MMD -g
STM32_ASM_FLAGS := $(STM32_CC_FLAGS)
STM32_LD_SCRIPT := STM32G473RETx_FLASH.ld
STM32_LD_FLAGS := $(STM32_COMMON_FLAGS) -static -Wl,--gc-sections -T $(STM32_LD_SCRIPT)


# Sources
MAIN_SRC := src/main.c
MAIN_INC := -I src
STM32_MAIN_OBJ := $(MAIN_SRC:%.c=$(STM32_BUILD_DIR)/obj/%.o)

APP_SRCS := $(shell find src/app/ -type f -name "*.c")
APP_ASMS := $(shell find src/app/ -type f -name "*.s")
APP_INCLUDE := -I src/app
STM32_APP_OBJS := $(APP_SRCS:%.c=$(STM32_BUILD_DIR)/obj/%.o) $(APP_ASMS:%.s=$(STM32_BUILD_DIR)/obj/%.o)

# Library locations
STM32CUBE_DIR := lib/STM32CubeG4
STM32CUBE_HAL_DIR := $(STM32CUBE_DIR)/Drivers/STM32G4xx_HAL_Driver
STM32CUBE_CMSIS_DIR := $(STM32CUBE_DIR)/Drivers/CMSIS/Device/ST/STM32G4xx

STM32CUBE_SRC_DIRS := $(STM32CUBE_HAL_DIR)/Src
STM32CUBE_SRCS := $(shell find $(STM32CUBE_SRC_DIRS) -maxdepth 1 -type f -name "*.c") $(STM32CUBE_CMSIS_DIR)/Source/Templates/system_stm32g4xx.c
STM32CUBE_ASMS := $(STM32CUBE_CMSIS_DIR)/Source/Templates/gcc/startup_stm32g473xx.s
STM32CUBE_INCLUDES := $(STM32CUBE_HAL_DIR)/Inc $(STM32CUBE_DIR)/Drivers/CMSIS/Include $(STM32CUBE_CMSIS_DIR)/Include
STM32CUBE_INCLUDES := $(foreach d, $(STM32CUBE_INCLUDES),-I $d)
STM32CUBE_OBJS := $(STM32CUBE_SRCS:%.c=$(STM32_BUILD_DIR)/obj/%.o) $(STM32CUBE_ASMS:%.s=$(STM32_BUILD_DIR)/obj/%.o)


# Compilation targets
.PHONY: all
all: ssdb

.PHONY: ssdb
ssdb: $(STM32_BUILD_DIR)/$(PROJECT_NAME)-$(PROJECT_VERSION).elf $(STM32_BUILD_DIR)/$(PROJECT_NAME)-$(PROJECT_VERSION).bin

$(STM32_BUILD_DIR)/$(PROJECT_NAME)-$(PROJECT_VERSION).bin: $(STM32_BUILD_DIR)/$(PROJECT_NAME)-$(PROJECT_VERSION).elf
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(STM32_OBJCOPY) -O binary $< $@

$(STM32_BUILD_DIR)/$(PROJECT_NAME)-$(PROJECT_VERSION).elf: $(STM32_MAIN_OBJ) $(STM32_APP_OBJS) $(STM32CUBE_OBJS)
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(STM32_LD) $(STM32_LD_FLAGS) $^ -o $@

$(STM32_BUILD_DIR)/obj/%.o: %.c
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(STM32_CC) $(STM32_CC_FLAGS) $(MAIN_INC) $(APP_INCLUDE) $(STM32CUBE_INCLUDES) -c $< -o $@

$(STM32_BUILD_DIR)/obj/%.o: %.s
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(STM32_CC) $(STM32_ASM_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
