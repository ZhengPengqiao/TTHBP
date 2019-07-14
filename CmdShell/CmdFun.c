/*******************************************************************************
 * 文件名称：CmdFun.h
 * 作者    ：  郑朋桥
 * 文件介绍： 用来控制8052的直接函数
 * 
 ******************************************************************************/

#include "CmdFun.h"

/**
 * @brief Set the Pin Status object
 * 
 * @param pin : 需要配置的引脚
 * @param status : 配置引脚的状态
 * @return int : 
 *  C_RSP_SUCCESS           :Ok 
 *  C_RSP_PIN_PINID_INVALID :pin参数错误
 *  C_RSP_PIN_VAL_INVALID   :状态值非法
 */
int setPin_Status(char pin, char status)
{
    int val;
    if ((pin == C_PIN_P0_ALL) || (pin == C_PIN_P1_ALL) || (pin == C_PIN_P2_ALL) ||
        (pin == C_PIN_P3_ALL) || (pin == C_PIN_P4_ALL))
    {
        val = status;
    }
    else
    {
        if (status)
        {
            val = 1;
        }
        else
        {
            val = 0;
        }
    }

    switch (pin)
    {
    case C_PIN_P0_PIN0:
        P0_PIN0 = val;
        break;
    case C_PIN_P0_PIN1:
        P0_PIN1 = val;
        break;
    case C_PIN_P0_PIN2:
        P0_PIN2 = val;
        break;
    case C_PIN_P0_PIN3:
        P0_PIN3 = val;
        break;
    case C_PIN_P0_PIN4:
        P0_PIN4 = val;
        break;
    case C_PIN_P0_PIN5:
        P0_PIN5 = val;
        break;
    case C_PIN_P0_PIN6:
        P0_PIN6 = val;
        break;
    case C_PIN_P0_PIN7:
        P0_PIN7 = val;
        break;
    case C_PIN_P0_ALL:
        P0_ALL = val;
        break;
    case C_PIN_P1_PIN0:
        P1_PIN0 = val;
        break;
    case C_PIN_P1_PIN1:
        P1_PIN1 = val;
        break;
    case C_PIN_P1_PIN2:
        P1_PIN2 = val;
        break;
    case C_PIN_P1_PIN3:
        P1_PIN3 = val;
        break;
    case C_PIN_P1_PIN4:
        P1_PIN4 = val;
        break;
    case C_PIN_P1_PIN5:
        P1_PIN5 = val;
        break;
    case C_PIN_P1_PIN6:
        P1_PIN6 = val;
        break;
    case C_PIN_P1_PIN7:
        P1_PIN7 = val;
        break;
    case C_PIN_P1_ALL:
        P1_ALL = val;
        break;
    case C_PIN_P2_PIN0:
        P2_PIN0 = val;
        break;
    case C_PIN_P2_PIN1:
        P2_PIN1 = val;
        break;
    case C_PIN_P2_PIN2:
        P2_PIN2 = val;
        break;
    case C_PIN_P2_PIN3:
        P2_PIN3 = val;
        break;
    case C_PIN_P2_PIN4:
        P2_PIN4 = val;
        break;
    case C_PIN_P2_PIN5:
        P2_PIN5 = val;
        break;
    case C_PIN_P2_PIN6:
        P2_PIN6 = val;
        break;
    case C_PIN_P2_PIN7:
        P2_PIN7 = val;
        break;
    case C_PIN_P2_ALL:
        P2_ALL = val;
        break;
    case C_PIN_P3_PIN0:
        P3_PIN0 = val;
        break;
    case C_PIN_P3_PIN1:
        P3_PIN1 = val;
        break;
    case C_PIN_P3_PIN2:
        P3_PIN2 = val;
        break;
    case C_PIN_P3_PIN3:
        P3_PIN3 = val;
        break;
    case C_PIN_P3_PIN4:
        P3_PIN4 = val;
        break;
    case C_PIN_P3_PIN5:
        P3_PIN5 = val;
        break;
    case C_PIN_P3_PIN6:
        P3_PIN6 = val;
        break;
    case C_PIN_P3_PIN7:
        P3_PIN7 = val;
        break;
    case C_PIN_P3_ALL:
        P3_ALL = val;
        break;
    case C_PIN_P4_PIN0:
        P4_PIN0 = val;
        break;
    case C_PIN_P4_PIN1:
        P4_PIN1 = val;
        break;
    case C_PIN_P4_PIN2:
        P4_PIN2 = val;
        break;
    case C_PIN_P4_PIN3:
        P4_PIN3 = val;
        break;
    case C_PIN_P4_ALL:
        P4_ALL = val;
        break;
    default:
        return C_RSP_PIN_PINID_INVALID;
    }
    return C_RSP_SUCCESS;
}