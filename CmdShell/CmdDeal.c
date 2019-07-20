/*******************************************************************************
 * 文件名称：CmdDeal.h
 * 作者    ：  郑朋桥
 * 文件介绍： 处理相应的指令函数的实现
 * 
 ******************************************************************************/

#include "CmdDeal.h"
#include "TIMER.h"
#include "CmdFun.h"
#include "LED.h"

char data1;

/*
 * 函数名称 ： dc_dealStrCmd
 * 函数介绍 ： 处理字符串指令
 * 参数介绍 ： uartDataBuff : 缓存命令的字符串
 *           cmdLen ： 第一条命令的长度
 * 返回值   : 处理结果（还未定义）
 */
int dc_dealStrCmd(char *uartDataBuff, int cmdLen)
{
	sendString(uartDataBuff, cmdLen);
    return 0;
}


/*
 * 函数名称 ： dc_dealBinCmd
 * 函数介绍 ： 处理二进制指令
 * 参数介绍 ： uartDataBuff : 缓存命令的字符串
 *           cmdLen ： 第一条命令的长度
 * 返回值   : 0:Ok 其他:Err
 */
int dc_dealBinCmd(char *uartDataBuff, int cmdLen)
{
    CmdFormat_t cmdElement;
	char checksum;
	int i;
    int ret = 0;
    (void)cmdLen;

    setLedToggle();

    cmdElement.cmdType = uartDataBuff[0];
    cmdElement.frameId = uartDataBuff[1];
    cmdElement.dataLength   = uartDataBuff[2] & 0xF;
    checksum = uartDataBuff[0] ^ uartDataBuff[1] ^ uartDataBuff[2];//计算校验和

    for(i = 0; i < cmdElement.dataLength; i++)
    {
        cmdElement.data[i] = uartDataBuff[3+i];
        checksum ^= cmdElement.data[i];  ////计算校验和
    }

    //将Uart数据中的校验和存入cmdElement.checksum
    cmdElement.checksum     = uartDataBuff[3+cmdElement.dataLength];

    //校验正确加入处理队列。
    if( checksum == cmdElement.checksum )
    {
        switch ( cmdElement.cmdType )
        {
            case C_PIN_SET:
            {
                ret = setPin_Status(cmdElement.data[0], cmdElement.data[1]);
                if( ret == 0 )
                {
                    dc_sendRsp_Code(cmdElement.cmdType, cmdElement.frameId, C_RSP_SUCCESS);
                    return C_RSP_SUCCESS;
                }
                else
                {
                    dc_sendRsp_Code(cmdElement.cmdType, cmdElement.frameId, ret);
                    return ret;
                }
            }
            break;
            case C_PIN_GET:
            {
                ret = getPin_Status(cmdElement.data[0], &data1);
                if( ret == 0 )
                {
                    dc_sendRsp_Code(cmdElement.cmdType, cmdElement.frameId, C_RSP_SUCCESS);
                    return C_RSP_SUCCESS;
                }
                else
                {
                    dc_sendRsp_Code(cmdElement.cmdType, cmdElement.frameId, ret);
                    return ret;
                }
            }
            break;
            
            default:
            {
                dc_sendRsp_Code(cmdElement.cmdType, cmdElement.frameId, C_RSP_UNDEFINE);
                return C_RSP_UNDEFINE;
            }
            break;
        } 
    }
    else
    {
        dc_sendRsp_Code(cmdElement.cmdType, cmdElement.frameId, C_RSP_CHECKSUM_ERR);
        return C_RSP_CHECKSUM_ERR;
    }

    return C_RSP_RUN_ERR;
}


/*
 * 函数名称 ： dc_sendRsp_Code
 * 函数介绍 ： 将指定的响应状态发送到串口
 * 参数介绍 ： 
 * 返回值   : 处理结果（还未定义）
 */
int dc_sendRsp_Code(int cmdType, char frameId, int rspCode)
{
    CmdRSPFormat_t rsp;
    rsp.cmdType = C_CMD_RSP;
    rsp.cmdTypeRsp = cmdType;
    rsp.frameId = frameId;
    rsp.rspCode = rspCode;
    rsp.data1 = data1;
    rsp.checksum = C_CMD_RSP ^ cmdType ^ frameId ^ rspCode ^ rsp.data1;
	sendString((char*)rsp,sizeof(rsp));

    dc_sendCmdEnd();

    return 0;
}


/**********************************************************************
 * 供内部使用的函数
 **********************************************************************/

/*
 * 函数名称 : dc_sendCmdEnd
 * 函数介绍 : 发送指令结束符
 * 参数介绍 : 无
 * 返回值  :  无
 */
void dc_sendCmdEnd()
{
    char str[2];
    str[0] = UARTENDCHARFIRST;
    str[1] = UARTENDCHARSECOND;
	sendString(str,2);
}