#ifndef ENCODER_H_
#define ENCODER_H_
#include <stm32f10x.h>
void Encoder_init(void);
int16_t getEncodeCount(void);
void TIM_Ecoder_init(void);
int16_t TIM_Encoder_get(void);
#endif