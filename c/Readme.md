# Bare-Metal C for STM32F4

A minimal bare-metal C project for STM32F4 (Cortex-M4) without any vendor HAL or SDK dependencies.

## Purpose

This project demonstrates the fundamentals of bare-metal embedded development:
- Custom startup code and vector table
- Linker script for memory layout
- No external dependencies (HAL, CMSIS, etc.)

## Target Hardware

* NUCLEO-F401RE

## Project Structure

```
c/
├── main.c          # Application entry point (LED blink)
├── startup.c       # Hardware startup process (vector table, Reset_Handler)
├── memory.ld       # Linker script (memory regions, sections)
├── Makefile        # Build system
└── build/          # Output directory (generated)
    ├── main.o
    ├── startup.o
    └── output.elf
```

## Prerequisites

- **Toolchain**: `arm-none-eabi-gcc` (tested with GCC 14.2.1)
- **Make**: GNU Make
- **OpenOCD**: For flashing the binary to the target, can be also used for debugging (optional).

***Note***: Other tools like `st-flash` can be used for flashing as well.

## Building

```bash
# Build the project
make

# Check binary size
make size

# Clean build artifacts
make clean
```

## Flashing

OpenOCD path must be provided via environment variable or command-line argument:

```bash
# Option 1: Pass as argument
make flash OPENOCD=/path/to/openocd

# Option 2: Set environment variable
export OPENOCD=/path/to/openocd
make flash
```

**Available targets:**

```bash
# Flash to target
make flash

# Erase flash memory
make erase
```

## Memory Layout

```
FLASH (0x08000000)
┌──────────────────────┐
│ Initial SP (4 bytes) │  ← Stack pointer value
├──────────────────────┤
│ Vector Table         │  ← Reset_Handler, NMI, HardFault, etc.
├──────────────────────┤
│ .text (code)         │
├──────────────────────┤
│ .rodata (constants)  │
├──────────────────────┤
│ .data (init values)  │  ← LMA (Load Memory Address)
└──────────────────────┘

RAM (0x20000000)
┌──────────────────────┐
│ .data (initialized)  │  ← VMA (copied from Flash at startup)
├──────────────────────┤
│ .bss (zero-init)     │  ← Zeroed by startup code
├──────────────────────┤
│ Heap ↓               │
│                      │
│               ↑ Stack│
└──────────────────────┘ ← 0x20020000 (Initial SP)
```

## Startup Sequence

1. **Hardware**: Loads SP from 0x08000000, jumps to Reset_Handler at 0x08000004
2. **Reset_Handler**:
   - Copies `.data` section from Flash to RAM
   - Zeros `.bss` section
   - Calls `main()`

***Note***:

## Key Files Explained

### startup.c
- Defines the interrupt vector table (98 entries for STM32F4)
- Weak aliases for all handlers → default to infinite loop
- `Reset_Handler` initializes C runtime before `main()`

### memory.ld
- Defines FLASH and RAM memory regions
- Places vector table at 0x08000000 (first entry is initial SP)
- Exports linker symbols (`_sdata`, `_edata`, `_sbss`, `_ebss`) for startup code

### main.c
- Configures GPIOA pin 5 as output (onboard LED)
- Toggles LED in a loop

## Compiler Flags

| Flag | Purpose |
|------|---------|
| `-mcpu=cortex-m4` | Target Cortex-M4 core |
| `-mthumb` | Use Thumb instruction set |
| `-mfloat-abi=soft` | Software floating point |
| `-ffunction-sections` | Place each function in its own section |
| `-fdata-sections` | Place each variable in its own section |
| `-Wl,--gc-sections` | Remove unused sections (dead code elimination) |
| `-nostartfiles` | Don't use standard startup files |
| `--specs=nano.specs` | Use newlib-nano (smaller C library) |
| `--specs=nosys.specs` | No OS syscalls |

