#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);
void UART_BindPin(void);
void UART_Transmit(const char* string);
unsigned char UART_ReadFlag(void);

void UART_PrintInt(unsigned short number);



#endif
