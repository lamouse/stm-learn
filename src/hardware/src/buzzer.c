#include <buzzer.h>

void Buzzer_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin){
    GPIO_ResetBits(GPIOx, GPIO_pin);
}

void Buzzer_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin){
    GPIO_SetBits(GPIOx, GPIO_pin);
}

void Buzzer_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin){
    if(GPIO_ReadOutputDataBit(GPIOx, GPIO_pin) == 0){
        Buzzer_OFF(GPIOx, GPIO_pin);
    }else{
        Buzzer_ON(GPIOx, GPIO_pin);
    }
}