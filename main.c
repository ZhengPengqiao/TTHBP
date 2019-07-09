#include "TIMER.h"
#include "UART.h"
#include "LED.h"
#include "stdio.h"

#define SYS_UART_RATE 9600 //配置系统串口的波特率

void main()
{
	char ch[22];
	initUart(SYS_UART_RATE);
	sendString("system init ok",sizeof("system init ok"));
	sendNewLine();

	while(1)
	{
		readStringWait(ch,10);
		ch[10] = '\0';
		sendString(ch,10);
		sendNewLine();

		setLedToggle();
	}
}
