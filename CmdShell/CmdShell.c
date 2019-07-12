/*******************************************************************************
 * 文件名称：CmdShell.c
 * 作者    ：  郑朋桥
 * 文件介绍： 将解析到的数据,当做指令执行,用于响应PC的动作
 * 
 ******************************************************************************/

#include "CmdShell.h"
#include <string.h>


//定义长度为UARTDATABUFFLENGTH的缓冲数组
__xdata char uartDataBuff[UARTDATABUFFLENGTH];

/*
 * 函数名称 ： uartReceiveBuffCmdDeal
 * 函数介绍 ： 对传过来的Uart数据进行处理，是放入DealQueue还是SendQueue.
 * 参数介绍 ： uartDataBuff : 缓存命令的字符串
 *           cmdLen ： 第一条命令的长度
 * 返回值   : 处理结果（还未定义）
 */
int uartReceiveBuffCmdDeal(char *uartDataBuff, int cmdLen)
{
	if( (uartDataBuff[0] == UARTSTRCHARFIRST) && (uartDataBuff[1] == UARTSTRCHARSECOND) )
	{
		dc_dealStrCmd(uartDataBuff, cmdLen);
	}
	else
	{
		dc_dealBinCmd(uartDataBuff, cmdLen);
	}
    return 0;
}


/*
 * 函数名称 ： uartReceiveBuffCmdClean
 * 函数介绍 ： 将缓存中的指令从缓存中清除，并将后面的数据前移
 * 参数介绍 ： uartDataBuff : 缓存命令的字符串
 *           cmdLen ： 第一条命令的长度
 *           buffLen ： uartDataBuff缓存中的数据个数,以指针传递，因为要改变buffLen的值
 * 返回值   : 处理结果（还未定义）
 */
int uartReceiveBuffCmdClean(char *uartDataBuff, int cmdLen, int *buffLen)
{
	int i = 0;

	for(i = 0; i < ( (*buffLen) - cmdLen - 1) ; i++)
	{
		uartDataBuff[i] = uartDataBuff[i+cmdLen+2];
	}
	(*buffLen) = (*buffLen) - cmdLen -2;
	return 0;
}


/*
 * 函数名称 ： uartReceiveBuffDeal
 * 函数介绍 ： 处理\n\r前的一条指令，并将处理后的那条指令移除
 * 			注意 ：
 * 				本函数将会清空uartDataBuff中已处理的数据，并将buffLen该为现有数据的长度
 * 参数介绍 ： uartDataBuff : 缓存Uart数据的字符串
 *           cmdLen ： 第一条命令的长度
 *           buffLen ： uartDataBuff缓存中的数据个数，以引用传递，因为要改变buffLen的值
 * 返回值   ： 处理结果（还未定义）
 *
 */
int uartReceiveBuffDeal(char *uartDataBuff, int cmdLen, int *buffLen)
{
	//处理已有的一条指令
	uartReceiveBuffCmdDeal(uartDataBuff, cmdLen);
	//将已经处理的那条指令从缓存中清除
	uartReceiveBuffCmdClean(uartDataBuff, cmdLen, buffLen);
	return 0;
}


/*
 * 函数名称 ： uartReceive
 * 函数介绍 ： 持续的从串口获得数据，并将数据解析成处理结构的元素
 * 参数介绍 ： pParam : 传给线程函数的参数
 * 返回值   : NULL
 */
void binShellThread()
{
	static int readLen = 0;   //每次读取到的数据长度
	static int buffLen = 0;    //现在uartDataBuff中已有的字符串长度
	int i = 0;         //用于for循环

    readLen = readString(uartDataBuff + buffLen, UARTDATABUFFLENGTH - buffLen);
    buffLen += readLen;

    //判断已接收的字符中是否有\n\r （Uart数据结束符）
    for(i = 0; i < buffLen-1; i++)
    {
    	//判断是否是特定字符（自定义的Uart数据终止符）
    	if( ( uartDataBuff[i] == UARTENDCHARFIRST ) \
    		&& ( uartDataBuff[i+1] == UARTENDCHARSECOND ) )
    	{
    		//处理并清除完整的Uart数据,每次最多处理一条数据
    		uartReceiveBuffDeal(uartDataBuff, i, &buffLen);
    		i = 0;  //从处理后的缓冲区中重新查找结束符
    	}
    }
}
