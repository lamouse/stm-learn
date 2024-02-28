#ifndef HARDWARE_H
#define HARDWARE_H
#include <stm32f10x.h>
void Hardward_Init(uint32_t RCC_APB2Periph, GPIO_InitTypeDef* init, GPIO_TypeDef* GPIOx);

#endif