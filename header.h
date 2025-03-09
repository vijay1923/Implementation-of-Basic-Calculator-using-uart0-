

// BLUTHOOTH Declarations 
extern void bluetooth(void );
extern void mannual(void );

// UART0 Declartions
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_init(unsigned int baud);
extern unsigned char uart0_rx(void );
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float num);
extern void uart0_rx_sting(char *s);
extern char *uart0_rx_string(char *s, int ele);
extern void uart0_hex(char ch);

