#ifndef KEY_H_
#define KEY_H_
#include <stm32f10x.h>
#include <delay.h>
void Key_Init(uint32_t RCC_APB2Periph, GPIO_InitTypeDef* init, GPIO_TypeDef* GPIOx);

uint8_t Key_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif