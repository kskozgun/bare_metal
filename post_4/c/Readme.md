# Bare-Metal C for STM32F4

A minimal bare-metal C project for STM32F4 (Cortex-M4) without any vendor HAL or SDK dependencies.

## Purpose

This project demonstrates the fundamentals of bare-metal embedded development:
- Custom startup code and vector table
- Linker script for memory layout
- Direct hardware register access via a lightweight GPIO abstraction layer
- No external dependencies (HAL, CMSIS, etc.)

## Target Hardware

* NUCLEO-F401RE

## Project Structure

```
c/
├── main.c              # Application entry point (LED blink via GPIO driver)
├── startup.c           # Hardware startup process (vector table, Reset_Handler)
├── memory.ld           # Linker script (memory regions, sections)
├── Makefile            # Build system
├── gpio.h              # GPIO abstraction – gpio_t struct and API declarations
├── gpio.c              # GPIO driver – clock enable, pin init, set/clear
├── stm32fxxx_regs.h    # Peripheral register definitions (RCC, GPIO)
└── build/              # Output directory (generated)
    ├── main.o
    ├── startup.o
    ├── gpio.o
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
- Declares a `gpio_t` descriptor for GPIOA pin 5 (onboard LED on NUCLEO-F401RE)
- Calls `gpio_init()` to enable the port clock and configure the pin as output
- Blinks the LED in a loop using `gpio_set()` / `gpio_clear()` with a simple NOP delay

### gpio.h / gpio.c
- `gpio_t` struct holds a port base pointer, pin number, and mode
- `gpio_init()` enables the AHB1 peripheral clock for the port and sets `MODER`
- `gpio_set()` / `gpio_clear()` drive the pin HIGH/LOW via the `ODR` register
- Clock enable is derived arithmetically from the port base address offset, avoiding a lookup table

### stm32fxxx_regs.h
- `GPIO_RegDef_t` struct mirrors the hardware register layout (MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR)
- Macro constants for `RCC_AHB1ENR`, all GPIO port bases, and MODER field helpers

## Compiler Flags

| Flag | Purpose |
|------|---------|
| `-mcpu=cortex-m4` | Target Cortex-M4 core |
| `-mthumb` | Use Thumb instruction set |
| `-mfloat-abi=soft` | Software floating point |
| `-std=c99` | Compile to the C99 standard |
| `-Os` | Optimize for size |
| `-Wall` | Enable common warnings |
| `-ffunction-sections` | Place each function in its own section |
| `-fdata-sections` | Place each variable in its own section |
| `-Wl,--gc-sections` | Remove unused sections (dead code elimination) |
| `-nostartfiles` | Don't use standard startup files |
| `--specs=nano.specs` | Use newlib-nano (smaller C library) |
| `--specs=nosys.specs` | No OS syscalls |

## GPIO API Design — Single API for All Ports

All STM32F4 GPIO ports share the same register layout and are laid out consecutively in memory (0x400 bytes apart). The design exploits this to serve every port and pin through one set of functions.

**1. Uniform register layout → one struct fits all ports**

`GPIO_RegDef_t` mirrors the hardware layout. Casting any port's base address to `GPIO_RegDef_t *` gives direct field access with no port-specific code:

```c
#define GPIOA_BASE  ((GPIO_RegDef_t *)0x40020000U)
#define GPIOB_BASE  ((GPIO_RegDef_t *)0x40020400U)
// ...
```

**2. Port descriptor struct → caller chooses the target**

`gpio_t` holds a pointer to the port, a pin number, and a mode. The caller fills it in; the driver never needs to know which port it is ahead of time:

```c
gpio_t green_led = { .gpio_base = GPIOA_BASE, .pin = 5, .mode = GPIO_MODE_OUTPUT };
gpio_t my_input  = { .gpio_base = GPIOC_BASE, .pin = 13, .mode = GPIO_MODE_INPUT };

gpio_init(&green_led);
gpio_init(&my_input);   // same function, different port
```

**3. Arithmetic clock enable → no switch/case needed**

The AHB1ENR clock-enable bit index matches the port order (bit 0 = GPIOA, bit 1 = GPIOB, …). The driver derives it at runtime from the pointer value:

```c
uint32_t port_idx = ((uint32_t)gpio_base - GPIO_PORT_BASE_ADDR) / GPIO_PORT_STRIDE;
RCC_AHB1ENR |= (1U << port_idx);
```

This means adding support for a new port requires nothing more than defining its base address macro.
