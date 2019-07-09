#ifndef __I2C_H_
#define __I2C_H_


#include "TTHBP.h"
#include "config.h"
#define I2CSCL P3_7
#define I2CSDA P3_6 
#define __nop() __asm NOP __endasm 
#define I2CDelay() 	{ __nop();__nop();__nop();__nop();__nop(); }




/*******************************************************************************
 * 函数名称 : i2cStart
 * 函数介绍 :	发送蓝牙起始位
 * 参数介绍 : 无
 * 返回值   : 无
 ******************************************************************************/
extern void i2cStart();

/*******************************************************************************
 * 函数名称 : i2cStop
 * 函数介绍 :	发送蓝牙停止位
 * 参数介绍 : 无
 * 返回值   : 无
 ******************************************************************************/
extern void i2cStop();

/*******************************************************************************
 * 函数名称 : i2cWrite
 * 函数介绍 :	发送一个字节
 * 参数介绍 : data : 将要发送的字节
 * 返回值   : 返回从机应答位
 ******************************************************************************/
extern char i2cWrite(unsigned char data);

/*******************************************************************************
 * 函数名称 : i2cReadNAK
 * 函数介绍 :	读取一个字节,发送发送非应答位
 * 参数介绍 : 无
 * 返回值   : 返回读取到的字节
 ******************************************************************************/
extern unsigned char i2cReadNAK();

/*******************************************************************************
 * 函数名称 : i2cReadACK
 * 函数介绍 :	读取一个字节,发送应答位
 * 参数介绍 : 无
 * 返回值   : 返回读取到的字节
 ******************************************************************************/
extern unsigned char i2cReadACK();



#endif  //__I2C_H_
