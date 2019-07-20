#include "TIMER.h"
#include "UART.h"
#include "LED.h"
#include "CmdShell.h"
#include "stdio.h"

#define SYS_UART_RATE 9600 //配置系统串口的波特率

/*
 * 函数名称 ： ledThread
 * 函数介绍 ： 定时刷新LED灯
 * 返回值   : NULL
 */
void ledThread()
{
	setLedToggle();
}

void main()
{
	initUart(SYS_UART_RATE);
	sendString("system init ok",sizeof("system init ok"));
	sendNewLine();

	addTIMER0Task(1000, ledThread, LED_TASK_TAG);

	while(1)
	{
		updateTIMER0();
		binShellThread();
	}
}
