#ifndef PWM_H_
#define PWM_H_
#include <stm32f10x.h>
void PWM_Init(void);
void set_compare(uint16_t compare);
#endif