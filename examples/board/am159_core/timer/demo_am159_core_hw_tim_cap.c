/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ��ʱ�� CAP �������̣�ͨ�� HW ��ӿ�ʵ��
 *
 * - �������裺
 *   1. ʹ�öŰ��ߣ��� PIOA_0 �� PIOA_6 ���ӡ�
 *
 * - ʵ������
 *   1. TIM2 ͨ�� PIOA_0 ������� 2KHz �� PWM��
 *   2. TIM3 ��������ͨ�� 1 ʹ�� PIOA_6 ���Ų���
 *   3. ���ڴ�ӡ�����ò����ܵõ��� PWM �źŵ����ں�Ƶ�ʡ�
 *
 * \note
 *    ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_9 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_am159_core_hw_tim_cap.c src_am159_core_hw_tim_cap
 *
 * \internal
 * \par Modification history
 * - 1.00 16-04-22  nwt, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_am159_core_hw_tim_cap
 * \copydoc demo_am159_core_hw_tim_cap.c
 */

/** [src_am159_core_hw_tim_cap] */
#include "ametal.h"
#include "am_clk.h"
#include "am_pwm.h"
#include "am_gpio.h"
#include "am_vdebug.h"
#include "am_zmf159.h"
#include "am_zmf159_clk.h"
#include "am_zmf159_inst_init.h"
#include "demo_zlg_entries.h"
#include "demo_am159_core_entries.h"

/**
 * \brief �������
 */
void demo_am159_core_hw_tim_cap_entry (void)
{
    am_pwm_handle_t pwm_handle = am_zmf159_tim2_pwm_inst_init();

    AM_DBG_INFO("demo am159_core hw tim cap!\r\n");

    /* TIM2 ���Ƶ��Ϊ 2KHz �� PWM */
    am_pwm_config(pwm_handle, 0, 500000 / 2, 500000);
    am_pwm_enable(pwm_handle, 0);

    /* ��ʼ������ */
    am_gpio_pin_cfg(PIOA_6, PIOA_6_TIM3_CH1 | PIOA_6_INPUT_FLOAT);

    /* ʹ�ܶ�ʱ��ʱ�� */
    am_clk_enable(CLK_TIM3);

    /* ��λ��ʱ�� */
    am_zmf159_clk_reset(CLK_TIM3);

    demo_zlg_hw_tim_cap_entry(ZMF159_TIM3,
                              AMHW_ZLG_TIM_TYPE1,
                              0,
                              am_clk_rate_get(CLK_TIM3),
                              INUM_TIM3);
}
/** [src_am159_core_hw_tim_cap] */

/* end of file */