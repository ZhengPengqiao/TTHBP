#include "TIMER.h"
#include "UART.h"
#include "LED.h"
#include "CmdShell.h"
#include "stdio.h"

#define SYS_UART_RATE 9600 //配置系统串口的波特率

void main()
{
	initUart(SYS_UART_RATE);
	sendString("system init ok",sizeof("system init ok"));
	sendNewLine();

	addTIMER0Task(5, binShellThread, SHELL_TASK_TAG);

	while(1)
	{
		updateTIMER0();
	}
}
