/*******************************************************************************
 * 文件名称：CmdFormat.h
 * 作者    ： 郑朋桥
 * 文件介绍： 定义指令的数据格式
 * 
 ******************************************************************************/


#ifndef __CMDFORMAT_H_
#define __CMDFORMAT_H_


/**
 * @brief 如果开头的两个字符是">:", 就说明是字符模式
 * 		  二进制协议中的头两个字节不能是0x3e 0x3a
 */
#define UARTSTRCHARFIRST 	0x3e  	// STR指令开始字符1 '>'
#define UARTSTRCHARSECOND 	0x3a  	// STR指令开始字符2 ':'

/**
 * @brief 遇到 字符":<" 或者 0x3a 0x3c 认为一条指令的结束
 */
#define UARTENDCHARFIRST 	0x3a  	// 指令结束字节1 ':'
#define UARTENDCHARSECOND 	0x3c  	// 指令结束字节2 '<'

/**
 * @brief cmdType:定义指令类型
 */
#define C_RUN_LINE 	0x1  // 运行指定的指令
#define C_RET_STAT 	0x2  // 请求指定的状态


/**
 * @brief responeCode:回复指令状态
 */
#define C_RSP_UNDEFINE 		0x01  	// 指令未定义
#define C_RSP_CHECKSUM_ERR 	0x02  	// 指令校验失败
#define C_RSP_SUCCESS  		0x03  	// 指令正确
#define C_RSP_ERR 			0x04  	// 指令错误

typedef struct CmdFormat
{
	char cmdType; 	 	    //指令编号
	char frameId;			//循环指令的frame号
	char dataLength;  	    //指令数据长度
    unsigned char data[16]; //可变的，长度由dataLength决定，按照其中的bit执行指定的
	                        //操作，长度在0~15byte之间
	char checksum;          //校验码
}CmdFormat_t;

typedef struct CmdRSPFormat
{
	char cmdType;           //指令编号
	char frameId;			//循环指令的frame号
	char rspCode;       	//返回码
	char checksum;          //校验码
}CmdRSPFormat_t;

#endif //__CMDFORMAT_H_