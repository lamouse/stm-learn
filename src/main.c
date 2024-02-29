#include <stm32f10x.h>
#include <delay.h>
#include <OLED.h>
#include <timer.h>
uint16_t timer_count = 0;

int main(void){
    OLED_Init();
    //OLED_ShowChar(1, 1, 'A');
    OLED_ShowString(1, 1, "TIME COUNT");
    Timer_Init();
    while (1)
    {
        OLED_ShowSignedNum(2, 1, timer_count, 4);
    }
}

void TIM2_IRQHandler(void){
    if(TIM_GetFlagStatus(TIM2, TIM_IT_Update) == SET){
        timer_count++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}