#ifndef PWM_H_
#define PWM_H_
#include <stm32f10x.h>
void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetPrescaler(uint16_t Prescaler);
#endif