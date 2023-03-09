#include "WaterPump.h"
// TMI2_CH3   PA2   pwm_front
// TIM2_CH4   PA3   pwm_back
// ARR=500   f=2KHZ

/**
 * @brief  ˮ�ó�ʼ�������Ϊ0��
 * @param  void
 * @retval void
 */
void WaterPump_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
    htim2.Instance->CCR3 = 0;
    htim2.Instance->CCR4 = 0;
}

/**
 * @brief  ˮ�õ���(��ת)
 * @param  uint8_t *duty   ˮ��ռ�ձȣ��仯��Χ0-100
 * @retval void
 */
void WaterPump_Speed(uint16_t *duty)
{
    uint16_t pwm_front = 0;
    uint16_t pwm_back = 0;
    pwm_front = (*duty) * 5;
    htim2.Instance->CCR3 = pwm_front;
    htim2.Instance->CCR4 = pwm_back;
}


