#include <key.h>

uint8_t Key_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    uint8_t key_num = 0;
    if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0){
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0)
        {
            Delay_ms(20);
        }
        key_num = 1;
    }
    return key_num;
}