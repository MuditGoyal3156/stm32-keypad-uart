# STM32F446RE Keypad UART Project (Bare-Metal C)

This project demonstrates how to interface a **4x4 keypad** with an **STM32F446RE** microcontroller using **bare-metal C** (no HAL/LL). When a key is pressed, it is sent over **UART** and displayed on a serial terminal such as **RealTerm**.

---

## Hardware Used

- STM32F446RE (Nucleo Board or bare chip)
- 4x4 Matrix Keypad
- USB to UART interface (ST-Link VCP or external UART-USB)
- LED (optional for debugging)

---

## Features

- Scans a 4x4 keypad matrix
- Displays pressed key via UART at **115200 baud**
- Minimal bare-metal code without STM32 HAL
- Custom UART and Keypad drivers


---

## Dependencies

> No external libraries or HAL drivers are used.

- `#include "stm32f4xx.h"` is used for register definitions.
- This file is part of the **CMSIS device headers**, automatically included with **STM32CubeIDE** or from [ST's STM32F4 CMSIS Pack](https://www.st.com/en/embedded-software/stm32cubef4.html).

To build this project, install **STM32CubeIDE** and create a project with the correct device selected (`STM32F446RETx`).

---

## 🔌 Serial Configuration

| Parameter | Value     |
|-----------|-----------|
| Baudrate  | **115200** |
| Data Bits | 8         |
| Stop Bit  | 1         |
| Parity    | None      |
| Flow Ctrl | None      |

Use **RealTerm**, **TeraTerm**, or any serial monitor to view output.


---

## Wiring Details

The 4x4 keypad has **8 pins**: 4 rows and 4 columns. Here's how you can connect it:

### Keypad to STM32 Wiring

| Keypad Pin | Function | STM32 Pin           |
|------------|----------|---------------------|
| Pin 1      | Row 1    | PA10                |
| Pin 2      | Row 2    | PB10                |
| Pin 3      | Row 3    | PB4                 |
| Pin 4      | Row 4    | PB5                 |
| Pin 5      | Col 1    | PA6                 |
| Pin 6      | Col 2    | PA7                 |
| Pin 7      | Col 3    | PA8                 |
| Pin 8      | Col 4    | PA9                 |


**Note:**
- Rows are typically configured as inputs with pull-up.
- Columns are driven low one by one during scanning.

---

## How It Works

- Microcontroller scans columns one at a time.
- When a row goes LOW while scanning a column, it means that button is pressed.
- The detected key is transmitted over UART and visible in RealTerm.

---

## Build and Flash Instructions

1. Open the project in **STM32CubeIDE**.
2. Ensure correct device is selected (STM32F446RE).
3. Build the project (`Ctrl + B`).
4. Connect STM32 and flash (`Ctrl + F11`).
5. Open RealTerm and observe keypresses.

---

## License

This project is licensed under the [MIT License](./LICENSE).

---

## Acknowledgements

- Developed using STM32CubeIDE
- Inspired by classic keypad + UART examples in embedded systems
