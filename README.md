##  Calculator using UART0 on LPC2129

##  Project Overview
This project implements a **calculator application** on the **LPC2129 ARM7 microcontroller** using **UART0 communication**.  

The user enters an arithmetic expression (e.g., `12+34`, `50-7`, `6*8`, `40/5`) through a **serial terminal**.  
The LPC2129 parses the string, extracts operands and the operator, performs the calculation, and returns the **result over UART0**.  

---

##  Hardware & Software Requirements

### Hardware
- LPC2129 Development Board  
- USB-to-UART Converter (CP2102 / FTDI / CH340)  
- Jumper wires  
- 5V regulated power supply  

### Software
- **Keil uVision5**  
- **Flash Magic**  
- **Serial Terminal**   

---

##  Circuit Connections

| LPC2129 Pin | Function  | USB-UART Pin |
|-------------|-----------|--------------|
| P0.0 (TXD0) | UART0 TX  | RX (USB-UART) |
| P0.1 (RXD0) | UART0 RX  | TX (USB-UART) |
| GND         | Ground    | GND           |

**UART Settings**: `9600 baud`, `8 data bits`, `no parity`, `1 stop bit (8N1)`

---

## Features
  - Supports **Addition (+), Subtraction (-), Multiplication (*), Division (/)**  
  - Handles **negative numbers**  
  - Reads input as a string, parses operands and operator  
  - Displays result back to the terminal  
  - UART driver supports:
  - Integer & Float TX  
  - String TX/RX  
  - HEX format TX  

---

##  Project Structure
Calculator_UART0/
¦-- main.c # Calculator logic (parsing & arithmetic operations)
¦-- uart_driver.c # UART driver implementation (tx, rx, string, integer, float, hex)
¦-- header.h # Function declarations (UART + placeholders for Bluetooth/manual)
¦-- README.md # Project documentation

---

##  File Descriptions

###  `main.c`
- Initializes UART0 (`uart0_init(9600)`)  
- Prompts user with `"Enter the Expr :"`  
- Reads expression string using `uart0_rx_string()`  
- Extracts **first number** (handles negative sign), **operator**, and **second number**  
- Performs calculation using `switch-case`:
  - `+` ? Addition  
  - `-` ? Subtraction  
  - `*` ? Multiplication  
  - `/` ? Division  
  - Default ? Prints `"Invalid Operator"`  
- Displays `"Result : <value>"` via UART  

###  `header.h`
- Function prototypes for all UART operations:  
  - `uart0_tx`, `uart0_rx`, `uart0_tx_string`, `uart0_rx_string`  
  - `uart0_tx_integer`, `uart0_tx_float`, `uart0_hex`  
- Placeholders for:
  - `bluetooth()`  
  - `mannual()`  

###  `uart_driver.c`
Implements UART driver functions:
- `uart0_init()` ? Initialize UART0 with desired baud rate  
- `uart0_tx()` / `uart0_rx()` ? Send/receive single character  
- `uart0_tx_string()` / `uart0_rx_string()` ? Send/receive string  
- `uart0_tx_integer()` ? Transmit integers as ASCII text  
- `uart0_tx_float()` ? Transmit floating-point numbers  
- `uart0_hex()` ? Print characters in HEX  

---

##  How to Run
1. Compile project in **Keil uVision**.  
2. Generate and flash `.hex` file to LPC2129 using **Flash Magic**.  
3. Open serial terminal (correct COM port).  
4. Configure ? **9600 baud, 8N1**.  
5. Enter arithmetic expressions and view results.  

---

##  Flow of Execution
flowchart 
    A[Start] --> [UART0 Init]
    B --> C[Prompt User: "Enter the Expr"]
    C --> D[Receive Expression via UART]
    D --> E[Parse First Number]
    E --> F[Parse Operator]
    F --> G[Parse Second Number]
    G --> H[Perform Calculation]
    H --> I[Send Result via UART]
    I --> C[Wait for Next Expression]


