# Bare-Metal Programming for STM32F4

A comparative study of bare-metal embedded development using **C**, **C++**, and **Rust** on STM32F4 (Cortex-M4) — without vendor HAL or SDK.

## Purpose

This repository explores different programming languages for bare-metal embedded development, comparing:
- Code size and performance
- Startup code and memory initialization
- Build systems and toolchains
- How modern C++ and Rust features (type safety, zero-cost abstractions, ownership, etc.) can be leveraged for safer and more expressive embedded systems, compared to C

## Target Hardware

| Property | Value |
|----------|-------|
| MCU | STM32F411 (ARM Cortex-M4) |
| Board | NUCLEO-F411RE |
| Flash | 512 KB @ 0x08000000 |
| RAM | 128 KB @ 0x20000000 |

## Implementations

| Language | Status | Link |
|----------|--------|------|
| C | ✅ Complete | [c/](c/) |
| C++ | 🚧 Planned | — |
| Rust | 🚧 Planned | — |

## License

MIT
