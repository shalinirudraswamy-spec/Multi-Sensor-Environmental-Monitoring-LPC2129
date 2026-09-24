//------ DELAY 1-------
extern void delay_sec(unsigned int );
extern void delay_ms(unsigned int );

//-------- LCD ----------
extern void lcd_data(unsigned char );
extern void lcd_cmd(unsigned char );
extern void lcd_init(void);
extern void lcd_str(char *);
extern int lcd_len(char *p);
extern void lcd_int(int num);
extern void lcd_float(float );

//------ DELAY 2-------
extern void Delay_sec(unsigned int );
extern void Delay_ms(unsigned int );

//---------UART---------------
extern void uart_tx(unsigned char );
extern void uart_init(unsigned int );
extern void uart_str(char *);
extern unsigned char uart_rx(void);
extern void uart_tx_int(int );
extern void uart_tx_float(float);

//-----------ADC-----------------
extern unsigned int adc_read(unsigned int);
extern void adc_init(void);

//-----------interupt------------
extern void ext_int0(void);
extern void vic_for_eint0(void);
extern void ext_int1(void);


extern void vic_for_uart0(void);
extern void config_uart0_intrr(void);
