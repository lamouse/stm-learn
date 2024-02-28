#include <stm32f10x.h>
#include <delay.h>
int main(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef init;
    init.GPIO_Mode = GPIO_Mode_Out_PP;
    uint16_t pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
    init.GPIO_Pin = pin;
    init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &init);

    GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
    while(1)
    {
        GPIO_Write(GPIOA, ~0x0001);
        Delay_s(1);
        GPIO_Write(GPIOA, ~0x0002);
        Delay_s(1);
        GPIO_Write(GPIOA, ~0x0004);
        Delay_s(1);
    }
}