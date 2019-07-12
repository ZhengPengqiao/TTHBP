/*******************************************************************************
 * 文件名称：CmdShell.h
 * 作者    ：  郑朋桥
 * 文件介绍： 将解析到的数据,当做指令执行,用于响应PC的动作
 * 
 ******************************************************************************/


#ifndef __CMDSHELL_H_
#define __CMDSHELL_H_
#include "TTHBP.h"
#include "config.h"
#include "UART.h"
#include "TIMER.h"
#include "CmdFormat.h"
#include "CmdDeal.h"

/*
 * 函数名称 ： uartReceive
 * 函数介绍 ： 持续的从串口获得数据，并将数据解析成处理结构的元素
 * 参数介绍 ： pParam : 传给线程函数的参数
 * 返回值   : NULL
 */
void binShellThread();

#endif //__CMDSHELL_H_