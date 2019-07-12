#ifndef __CONFIG_H_
#define __CONFIG_H_

#define timer0TaskCount 10   //可以使用的任务数为timer0TaskCount+1，有一个用于任务切换
#define RX_BUFFER_SIZE 50    //UART接受缓冲区大小
#define TX_BUFFER_SIZE 50    //UART发送缓冲区大小


#define UARTDATABUFFLENGTH 1000 //定义缓存长度
/**
 * 一条完整数据最长为UARTONEDATAMAXLENGTH，也就是说如果接收UARTONEDATAMAXLENGTH
 * 个字符中还未找到一条完整的Uart数据，则说明这条数据有问题 
 */
#define UARTONEDATAMAXLENGTH 30

// 定义任务TAG
#define SHELL_TASK_TAG  1   //定义shell解析任务的TAG
#define LED_TASK_TAG    2   //定义LED闪烁任务的TAG

#endif
