#include <stm32f10x.h>
#include <delay.h>
int main(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef init;
    init.GPIO_Mode = GPIO_Mode_Out_PP;
    init.GPIO_Pin = GPIO_Pin_0;
    init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &init);

    GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
    while(1)
    {
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
        Delay_s(1);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
        Delay_s(1);
    }
}