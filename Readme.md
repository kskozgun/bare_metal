# Bare-Metal Programming for STM32F4

A comparative study of bare-metal embedded development using **C**, **C++**, and **Rust** on STM32F4 (Cortex-M4) — without vendor HAL or SDK.

The repository based on the blog series at [here](https://medium.com/@ozgunkgunyeli/22195bda80a2). You can find each posts in there.

## Purpose

This repository explores different programming languages for bare-metal embedded development, comparing:
- Code size and performance
- Build systems and toolchains
- How modern C++ and Rust features (type safety, zero-cost abstractions, ownership, etc.) can be leveraged for safer and more expressive embedded systems, compared to C.

## Target Hardware

| Property | Value |
|----------|-------|
| MCU | STM32F411 (ARM Cortex-M4) |
| Board | NUCLEO-F411RE |
| Flash | 512 KB @ 0x08000000 |
| RAM | 128 KB @ 0x20000000 |

## Toolchains

| Toolchain | Version | Notes |
|-----------|---------|-------|
| ARM GNU (arm-none-eabi) | 14.2.4 | For C and C++ |
| Makefile | GNU Make 3.81 | Build system for C and C++ |
| OpenOCD | 0.12.0 | For flashing and debugging |
| Rust | TBD | TBD |

## Blog Series

| Post | Status | Link | Notes |
|----------|--------|------| -----|
| Post-1 | ✅ Complete | [Post](https://medium.com/@ozgunkgunyeli/22195bda80a2)  | Bare-metal C setup and blink example |
| Post-2 | ✅ Complete | [Post](https://medium.com/@ozgunkgunyeli/from-scratch-exploring-bare-metal-c-vs-c-part-2-22195bda80a2) | Transform bare-metal from C to C++ |
| Post-3 | 🚧 Planned | — | Reduce binary size of C++ and compare with C |

## License

MIT
