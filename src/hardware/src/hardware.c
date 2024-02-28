#include <hardware.h>

void Hardward_Init(uint32_t RCC_APB2Periph, GPIO_InitTypeDef* init, GPIO_TypeDef* GPIOx){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
    GPIO_Init(GPIOx, init);
}
