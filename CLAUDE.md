# Pool Cover Control — Claude Preferences

## Writing Style

Always write in a professional and clear manner. No emoticons. Do not use dashes in titles or as inline clarifiers (e.g. "Title — Subtitle" or "value — explanation"). Use a colon or restructure the sentence instead. Dashes as standard list markers are acceptable.

## Diagrams

Always use Mermaid for all diagrams: block diagrams, flowcharts, state machines, schematic topology, board zone allocation, and any other visual representation. Never use ASCII art.

## Git

Always use conventional commits. Format: `type(scope): description` — types are `feat`, `fix`, `docs`, `chore`, `refactor`, `test`. Keep the message on one line unless a body is strictly necessary.

## Design Process

Design decisions are locked in `DESIGN.md`. Walk through changes item by item, waiting for explicit approval before moving to the next. When updating `DESIGN.md`, all locked items are written in final form with no pending markers.

The designer executes all schematic, layout, and firmware work. Claude performs structured review at defined gates.

## Project Context

Target manufacturer: JLCPCB (PCB fabrication and PCBA)
Schematic and layout tool: KiCad
Component sourcing: LCSC
Language: English for all technical documentation
