#ifndef LED_H_
#define LED_H_
#include <stm32f10x.h>

void LED_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);

void LED_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);

void LED_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);

#endif