#include <timer.h>

// extern timer_count;
void Timer_Init(void){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_InternalClockConfig(TIM2);
    TIM_TimeBaseInitTypeDef timer_init;
    timer_init.TIM_ClockDivision = TIM_CKD_DIV1;
    timer_init.TIM_CounterMode = TIM_CounterMode_Up;
    timer_init.TIM_Period = 10000 - 1;
    timer_init.TIM_Prescaler = 7200-1;
    timer_init.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timer_init);

    TIM_ClearFlag(TIM2,  TIM_FLAG_Update);
    TIM_ITConfig(TIM2, TIM_FLAG_Update, ENABLE);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef nvic_init;
    nvic_init.NVIC_IRQChannel = TIM2_IRQn;
    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    nvic_init.NVIC_IRQChannelPreemptionPriority = 2;
    nvic_init.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&nvic_init);


    TIM_Cmd(TIM2, ENABLE);
}

// void TIM2_IRQHandler(void){
//     if(TIM_GetFlagStatus(TIM2, TIM_IT_Update) == SET){
//         timer_count++;
//         TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//     }
// }