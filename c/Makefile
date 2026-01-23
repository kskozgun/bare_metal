#==============================================================================
# Bare-Metal STM32F4 Makefile
#==============================================================================

#------------------------------------------------------------------------------
# Toolchain
#------------------------------------------------------------------------------
CC        = arm-none-eabi-gcc
SIZE      = arm-none-eabi-size

#------------------------------------------------------------------------------
# Target Configuration
#------------------------------------------------------------------------------
TARGET    = output
MCU       = cortex-m4
LDSCRIPT  = memory.ld

#------------------------------------------------------------------------------
# Directories
#------------------------------------------------------------------------------
BUILD_DIR = build

#------------------------------------------------------------------------------
# Source Files
#------------------------------------------------------------------------------
C_FILES   = main.c startup.c
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(C_FILES))

#------------------------------------------------------------------------------
# Compiler Flags
#------------------------------------------------------------------------------
# Architecture
ARCH_FLAGS  = -mcpu=$(MCU) -mthumb

# FPU (use -mfloat-abi=hard -mfpu=fpv4-sp-d16 for hardware FPU)
FPU_FLAGS   = -mfloat-abi=soft

# Language standard
STD_FLAGS   = -std=c99

# Optimization (-O0, -O1, -O2, -O3, -Os, -Og)
OPT_FLAGS   = -Os
# Dead code elimination
SECTION_FLAGS = -ffunction-sections -fdata-sections

# Warnings
WARN_FLAGS  = -Wall

# Combined compiler flags
CFLAGS = $(ARCH_FLAGS) $(FPU_FLAGS) $(STD_FLAGS) $(OPT_FLAGS) $(SECTION_FLAGS) $(WARN_FLAGS)

#------------------------------------------------------------------------------
# Linker Flags
#------------------------------------------------------------------------------
# C library specs
LIB_FLAGS   = --specs=nosys.specs --specs=nano.specs

# Startup
START_FLAGS = -nostartfiles

# Garbage collection (removes unused sections)
GC_FLAGS    = -Wl,--gc-sections

# Linker script
LD_FLAGS    = -T $(LDSCRIPT)

# Combined linker flags
LDFLAGS = $(ARCH_FLAGS) $(FPU_FLAGS) $(LIB_FLAGS) $(START_FLAGS) $(GC_FLAGS) $(LD_FLAGS)

#==============================================================================
# Build Rules
#==============================================================================
.PHONY: all clean flash erase size

all: $(BUILD_DIR) $(OBJ_FILES) $(BUILD_DIR)/$(TARGET).elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/$(TARGET).elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $@

#------------------------------------------------------------------------------
# Utility Targets
#------------------------------------------------------------------------------
size:
	$(SIZE) -A $(BUILD_DIR)/$(TARGET).elf

clean:
	rm -rf $(BUILD_DIR)

#------------------------------------------------------------------------------
# Flash/Debug Targets
#------------------------------------------------------------------------------
flash: $(BUILD_DIR)/$(TARGET).elf
	$(OPENOCD) -s ../scripts -f board/st_nucleo_f4.cfg \
		-c "init; reset halt; flash write_image erase $(BUILD_DIR)/$(TARGET).elf; reset run; exit"

erase:
	$(OPENOCD) -s ../scripts -f board/st_nucleo_f4.cfg \
		-c "init; reset halt; stm32f4x mass_erase 0; exit"