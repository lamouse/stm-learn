#ifndef ENCODER_H_
#define ENCODER_H_
#include <stm32f10x.h>
void Encoder_init();
int16_t getEncodeCount();
#endif