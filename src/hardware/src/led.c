#include <led.h>

void LED_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin){
    GPIO_ResetBits(GPIOx, GPIO_pin);
}

void LED_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin){
    GPIO_SetBits(GPIOx, GPIO_pin);
}

void LED_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin){
    if(GPIO_ReadOutputDataBit(GPIOx, GPIO_pin) == 0){
        LED_OFF(GPIOx, GPIO_pin);
    }else{
        LED_ON(GPIOx, GPIO_pin);
    }
}