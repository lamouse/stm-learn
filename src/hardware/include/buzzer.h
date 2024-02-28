#ifndef BUZZER_H_
#define BUZZER_H_
#include <stm32f10x.h>

void Buzzer_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);

void Buzzer_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);

void Buzzer_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_pin);
#endif
