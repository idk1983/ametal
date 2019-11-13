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
 * \brief LPTIM1 ��ʱ�� TIMING ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - ʵ������
 *   1. LED0 �� 5Hz ��Ƶ�ʷ�ת��(����������10Hz��led��ת����Ϊ10/2=5Hz)
 *
 * \note
 *   1.��am_hwconf_hc32f03x_lptim.c�ļ��У�__g_lptim1_timing_devinfo�豸��Ϣ�ṹ��ѡ��
 *             AMHW_HC32_LPTIM_FUNCTION_TIMER  ----------- ��ʱ��ģʽ
 *             AMHW_HC32_LPTIM_MODE_RELOAD     ----------- �Զ�����ģʽ
 *             AM_FALSE                          ----------- �ſعر�
 *             AM_TRUE                           ----------- TOG��TOGN���ʹ�ܴ�
 *
 * \par Դ����
 * \snippet demo_hc32f03x_std_lptim1_timing.c src_hc32f03x_std_lptim1_timing
 *
 * \internal
 * \par Modification history
 * - 1.00 19-09-29  zp, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_hc32f03x_std_lptim1_timing
 * \copydoc demo_hc32f03x_std_lptim1_timing.c
 */

/** [src_hc32f03x_std_lptim1_timing] */

#include "ametal.h"
#include "am_vdebug.h"
#include "demo_std_entries.h"
#include "am_hc32f03x_inst_init.h"
#include "demo_amf03x_core_entries.h"

/**
 * \brief �������
 */
void demo_hc32f03x_core_std_lptim1_timing_entry (void)
{
    AM_DBG_INFO("demo amf03x_core std lptim1 timing!\r\n");

    demo_std_timer_timing_entry(am_hc32_lptim1_timing_inst_init(), 0);
}
/** [src_hc32f03x_std_lptim1_timing] */

/* end of file */