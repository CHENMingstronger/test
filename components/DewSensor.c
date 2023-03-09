#include "DewSensor.h"
#include "adc.h"

// ADC1-IN4  PA4

/**
 * @brief  ��¶��������ʼ����������ADC��ʼ��֮��
 * @param  void
 * @retval void
 */
void DewSensor_Init(void)
{
    HAL_ADCEx_Calibration_Start(&hadc1); // ADCУ׼
	  HAL_ADC_Start(&hadc1);
}

/**
 * @brief  ��¶��������ȡʪ����Ϣ
 * @param  float *humidity  ���ʪ��RH 0-100
 * @retval void
 */
void DewSensor_GetData(float *humidity)
{
    uint16_t ADC_Value;
    float voltage;

    HAL_ADC_PollForConversion(&hadc1, 50);
   
    
    ADC_Value = HAL_ADC_GetValue(&hadc1);
    
    voltage = (float)ADC_Value / 4096 * 3.3;
    *humidity = voltage;
}






