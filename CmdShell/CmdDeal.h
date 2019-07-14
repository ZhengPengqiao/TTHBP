/*******************************************************************************
 * 文件名称：CmdDeal.h
 * 作者    ：  郑朋桥
 * 文件介绍： 处理相应的指令函数
 * 
 ******************************************************************************/


#ifndef __CMDDEAL_H_
#define __CMDDEAL_H_

#include "CmdFormat.h"
#include "UART.h"

/*
 * 函数名称 ： dc_dealBinCmd
 * 函数介绍 ： 处理二进制指令
 * 参数介绍 ： uartDataBuff : 缓存命令的字符串
 *           cmdLen ： 第一条命令的长度
 * 返回值   : 处理结果（还未定义）
 */
int dc_dealBinCmd(char *uartDataBuff, int cmdLen);

/*
 * 函数名称 ： dc_dealStrCmd
 * 函数介绍 ： 处理字符串指令
 * 参数介绍 ： uartDataBuff : 缓存命令的字符串
 *           cmdLen ： 第一条命令的长度
 * 返回值   : 处理结果（还未定义）
 */
int dc_dealStrCmd(char *uartDataBuff, int cmdLen);


/**
 * @brief dc_sendRsp_Code
 * 
 * @param cmdType : 指令类型
 * @param frameId : frame id. 叠加的
 * @param rspCode : 响应码
 * @return int : 0:OK -1:Err
 */
int dc_sendRsp_Code(int cmdType, char frameId, int rspCode);


/**********************************************************************
 * 供内部使用的函数
 **********************************************************************/

/*
 * 函数名称 : dc_sendCmdEnd
 * 函数介绍 : 发送指令结束符
 * 参数介绍 : 无
 * 返回值  :  无
 */
void dc_sendCmdEnd();

#endif //__CMDDEAL_H_