/*******************************************************************************
 * 文件名称：CmdFormat.h
 * 作者    ： 郑朋桥
 * 文件介绍： 定义指令的数据格式
 * 
 ******************************************************************************/


#ifndef __CMDFORMAT_H_
#define __CMDFORMAT_H_


/******************************************************************************
 * @brief 定义指令的字符命令的开始标志和结束标志
 * 
 */
// 如果开头的两个字符是">:", 就说明是字符模式, 二进制协议中的头两个字节不能是0x3e 0x3a
#define UARTSTRCHARFIRST 	0x3e  	// STR指令开始字符1 '>'
#define UARTSTRCHARSECOND 	0x3a  	// STR指令开始字符2 ':'


// 遇到 字符":<" 或者 0x3a 0x3c 认为一条指令的结束
#define UARTENDCHARFIRST 	0x3a  	// 指令结束字节1 ':'
#define UARTENDCHARSECOND 	0x3c  	// 指令结束字节2 '<'
/*******************************************************************************/


/******************************************************************************
 * @brief cmdType:定义指令类型
 */
#define C_CMD_LINE 	0x1  // 运行指定的指令
#define C_STAT_GET 	0x2  // 请求指定的状态
#define C_PIN_SET 	0x3  // 设置指定的引脚
#define C_PIN_GET 	0x4  // 获取指定的引脚
#define C_REG_SET 	0x5  // 设置指定的寄存器
#define C_REG_GET 	0x6  // 获取指定的寄存器
#define C_CMD_RSP 	0x7  // 响应码
/*******************************************************************************/

/*******************************************************************************
 * @brief C_PIN_SET: 设置引脚的状态
 * -cmdType		: C_PIN_SET
 * -dataLength	: 0x02
 * 	-DATA[0] : PIN_NUM
 * 	-DATA[0] : PIN_STATUS
 */

// PIN_STATUS状态定义
#define C_PIN_STATUS_LOW   	0x00
#define C_PIN_STATUS_HEIG   0x01

// PIN_NUM引脚定义
#define C_PIN_P0_PIN0     0x00
#define C_PIN_P0_PIN1     0x01
#define C_PIN_P0_PIN2     0x02
#define C_PIN_P0_PIN3     0x03
#define C_PIN_P0_PIN4     0x04
#define C_PIN_P0_PIN5     0x05
#define C_PIN_P0_PIN6     0x06
#define C_PIN_P0_PIN7     0x07
#define C_PIN_P0_ALL      0x08

#define C_PIN_P1_PIN0     0x10
#define C_PIN_P1_PIN1     0x11
#define C_PIN_P1_PIN2     0x12
#define C_PIN_P1_PIN3     0x13
#define C_PIN_P1_PIN4     0x14
#define C_PIN_P1_PIN5     0x15
#define C_PIN_P1_PIN6     0x16
#define C_PIN_P1_PIN7     0x17
#define C_PIN_P1_ALL      0x18

#define C_PIN_P2_PIN0     0x20
#define C_PIN_P2_PIN1     0x21
#define C_PIN_P2_PIN2     0x22
#define C_PIN_P2_PIN3     0x23
#define C_PIN_P2_PIN4     0x24
#define C_PIN_P2_PIN5     0x25
#define C_PIN_P2_PIN6     0x26
#define C_PIN_P2_PIN7     0x27
#define C_PIN_P2_ALL      0x28

#define C_PIN_P3_PIN0     0x30
#define C_PIN_P3_PIN1     0x31
#define C_PIN_P3_PIN2     0x32
#define C_PIN_P3_PIN3     0x33
#define C_PIN_P3_PIN4     0x34
#define C_PIN_P3_PIN5     0x35
#define C_PIN_P3_PIN6     0x36
#define C_PIN_P3_PIN7     0x37
#define C_PIN_P3_ALL      0x38

#define C_PIN_P4_PIN0     0x40
#define C_PIN_P4_PIN1     0x41
#define C_PIN_P4_PIN2     0x42
#define C_PIN_P4_PIN3     0x43
#define C_PIN_P4_ALL      0x48
/*******************************************************************************/


/**
 * @brief responeCode:回复指令状态
 *  --ERR VAL
 */
#define C_RSP_SUCCESS  			0x00  	// 指令正确
#define C_RSP_UNDEFINE 			0x01  	// 指令未定义
#define C_RSP_CHECKSUM_ERR 		0x02  	// 指令校验失败
#define C_RSP_RUN_ERR 			0x03  	// 指令运行错误
#define C_RSP_PIN_PINID_INVALID 0x04  	// 指令PIN配置中pin脚错误
#define C_RSP_PIN_VAL_INVALID 	0x05  	// 指令PIN配置中值错误
#define C_RSP_ERR 				0x06  	// 指令错误

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
	char cmdTypeRsp;		//相应的那个指令类型
	char frameId;			//循环指令的frame号
	char rspCode;       	//返回码
	char data1;				//携带一个数据信息
	char checksum;          //校验码
}CmdRSPFormat_t;

#endif //__CMDFORMAT_H_