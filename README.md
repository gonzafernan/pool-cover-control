# Pool Cover Control Board

Electronic control board for an automatic residential pool cover. Drives a 12V DC brushed motor in both directions using a relay H-bridge, with inputs from a key switch and mechanical limit switches.

## Overview

The board replaces a failed original controller. It is designed for direct drop-in installation into the existing enclosure, preserving all external wiring and mechanical components.

## Hardware

- **MCU:** STM32G031K8T6 (ARM Cortex-M0+, 64MHz, no external crystal)
- **Motor control:** 4x Hongfa HF115F SPDT relays in H-bridge configuration, driven by ULN2003A
- **Power input:** 12V, up to 20A (fused), from external PSU in the same enclosure
- **Inputs:** 3-position maintained key switch, two NC limit switches
- **Protection:** Reverse polarity (P-FET), motor TVS, relay hardware interlock, firmware watchdog
- **PCB:** 100x100mm, 4-layer, 2oz copper, ENIG finish
- **Manufacturer:** JLCPCB

## Firmware

- Toolchain: STM32CubeMX + Makefile + GCC
- State machine: IDLE / OPENING / CLOSING / FAULT
- Motor timeout: 60 seconds
- Internal IWDG watchdog enabled

## Documentation

- [DESIGN.md](DESIGN.md) — Full hardware design specification
- [ROADMAP.md](ROADMAP.md) — Project phases and task checklist
