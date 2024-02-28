#include <light_sensor.h>

uint8_t LightSensor_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    return GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);

}