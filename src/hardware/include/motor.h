#ifndef MOTOR_H_
#define MOTOR_H_
#include <stm32f10x.h>
#include <pwm.h>

void Motor_init();
void Motor_SetSpeed(int8_t speed);
#endif