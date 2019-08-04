#include "TIMER.h"
#include "UART.h"
#include "LED.h"
#include "CmdShell.h"
#include "stdio.h"

#define SYS_UART_RATE 9600 //配置系统串口的波特率

void main()
{
	int i = 0;

	initUart(SYS_UART_RATE);
	sendString("system init ok",sizeof("system init ok"));
	sendNewLine();

	// 去掉定时器, 保证串口数据的性能

	while(1)
	{
		if( i > 5000 )
		{
			setLedToggle();
			i = 0;
		}
		i++;

		binShellThread();
	}
}
