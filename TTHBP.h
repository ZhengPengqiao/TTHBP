#ifndef __TTHBP_H_
#define __TTHBP_H_
#include <8052.h>
/********************************************************************************
*  引脚定义
********************************************************************************/
/*  BYTE Register  */
__sfr __at (0xE8) P4   ;
/* BIT Register  */
/* P4 */
__sbit __at (0xE8) P4_0 ;
__sbit __at (0xE9) P4_1 ;
__sbit __at (0xEA) P4_2 ;
__sbit __at (0xEB) P4_3 ;

#define LED     P4_0

#define P0_ALL      P0
#define P0_PIN0     P0_0
#define P0_PIN1     P0_1
#define P0_PIN2     P0_2
#define P0_PIN3     P0_3
#define P0_PIN4     P0_4
#define P0_PIN5     P0_5
#define P0_PIN6     P0_6
#define P0_PIN7     P0_7

#define P1_ALL      P1
#define P1_PIN0     P1_0
#define P1_PIN1     P1_1
#define P1_PIN2     P1_2
#define P1_PIN3     P1_3
#define P1_PIN4     P1_4
#define P1_PIN5     P1_5
#define P1_PIN6     P1_6
#define P1_PIN7     P1_7

#define P2_ALL      P2
#define P2_PIN0     P2_0
#define P2_PIN1     P2_1
#define P2_PIN2     P2_2
#define P2_PIN3     P2_3
#define P2_PIN4     P2_4
#define P2_PIN5     P2_5
#define P2_PIN6     P2_6
#define P2_PIN7     P2_7

#define P3_ALL      P3
#define P3_PIN0     P3_0
#define P3_PIN1     P3_1
#define P3_PIN2     P3_2
#define P3_PIN3     P3_3
#define P3_PIN4     P3_4
#define P3_PIN5     P3_5
#define P3_PIN6     P3_6
#define P3_PIN7     P3_7

#define P4_ALL      P4
#define P4_PIN0     P4_0
#define P4_PIN1     P4_1
#define P4_PIN2     P4_2
#define P4_PIN3     P4_3

#endif //__TTHBP_H_
