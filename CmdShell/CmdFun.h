/*******************************************************************************
 * 文件名称：CmdFun.h
 * 作者    ：  郑朋桥
 * 文件介绍： 用来控制8052的直接函数
 * 
 ******************************************************************************/


#ifndef __CMDFUN_H_
#define __CMDFUN_H_
#include "TTHBP.h"
#include "config.h"
#include "UART.h"
#include "CmdFormat.h"


int setPin_Status(char pin, char status);

#endif //__CMDFUN_H_