🔍 Project Overview

This project demonstrates how to build a UART-based calculator on the LPC2129 microcontroller.
Users can send arithmetic expressions (like 12+5, 2^3, 10%3) from a serial terminal.
The LPC2129 will:

✔ Read the expression
✔ Extract both numbers and operator
✔ Perform the computation
✔ Send the result back via UART0

This project is ideal for learning:

UART communication

String parsing

Embedded C

Operator handling

Bare-metal ARM7 programming

🛠 Supported Operations
Operator	Operation	Example	Output
+	Addition	10+3	13
-	Subtraction	8-12	-4
*	Multiplication	7*6	42
/	Division	20/4	5
%	Modulo	10%3	1
^	Power (Exponent)	2^5	32

Additional Features:

Handles negative numbers

Handles multi-digit numbers

Detects divide/mod-by-zero

Detects invalid operators

⚙️ Hardware Requirements

LPC2129 ARM7 Development Board

USB-to-UART converter (CP2102 / FTDI / CH340)

Jumper wires

5V regulated power supply

💻 Software Requirements

Keil uVision5 (IDE for ARM7)

Flash Magic (Programming tool)

Serial Monitor (PuTTY / RealTerm / Arduino Monitor)

🔌 Circuit Connections
LPC2129 Pin	Function	USB-UART Pin
P0.0 (TXD0)	TX	RX
P0.1 (RXD0)	RX	TX
GND	Ground	GND

UART Settings:

Baud Rate : 9600  
Data Bits : 8  
Parity    : None  
Stop Bits : 1  
(8N1)

🧩 Project Structure
Calculator_UART0/
│-- main.c          # Calculator logic
│-- uart_driver.c   # Low-level UART0 driver
│-- header.h        # Function declarations
│-- README.md       # Documentation

📌 main.c – Key Responsibilities

Initializes UART0

Displays menu

Reads expression string

Parses:

First number

Operator

Second number

Performs operation

Sends "Result : <value>" through UART

Handles:

Negative sign

Zero-division check

Invalid operator check

Exponentiation using loop

📡 UART Driver Capabilities (uart_driver.c)

uart0_init() → Initialize UART0

uart0_tx() → Send character

uart0_rx() → Receive character

uart0_tx_string() → Send string

uart0_rx_string() → Read string

uart0_tx_integer() → Send numbers over UART

Optional: Float & HEX TX support

▶️ How to Run the Project

Open project in Keil uVision5

Build → generate .hex

Open Flash Magic

Select LPC2129, correct COM port, baud = 9600

Flash the program

Open serial terminal

Enter inputs like:

12+5
-8*4
10/0
2^6

🔄 Execution Flow
flowchart TD
    A[Start] --> B[UART0 Init]
    B --> C[Send Menu]
    C --> D[Ask for Expression]
    D --> E[Receive via uart0_rx_string]
    E --> F[Parse Number 1]
    F --> G[Parse Operator]
    G --> H[Parse Number 2]
    H --> I[Perform Operation]
    I --> J[Send Result via UART]
    J --> C

🧪 Sample Serial Output
--------------------------------
            UART Calculator 
--------------------------------
Supported Operations:
  +   Addition
  -   Subtraction
  *   Multiplication
  /   Division
  %   Modulo
  ^   Power
--------------------------------
Enter the Expr : 12+5
Result : 17

Enter the Expr : 10/0
Error: Divide by Zero
