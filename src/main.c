#include <stm32f10x.h>
#include <delay.h>
int main(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef init;
    init.GPIO_Mode = GPIO_Mode_Out_PP;
    uint16_t pin = GPIO_Pin_12;
    init.GPIO_Pin = pin;
    init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &init);

    while(1)
    {
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);
        Delay_s(1);
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);
        Delay_s(1);
    }
}