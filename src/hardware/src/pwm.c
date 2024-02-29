#include <pwm.h>
#include <stm32f10x.h>

void PWM_Init(void){


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef init;
    init.GPIO_Mode = GPIO_Mode_AF_PP;
    init.GPIO_Pin = GPIO_Pin_2;
    init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &init);


    TIM_InternalClockConfig(TIM2);
    TIM_TimeBaseInitTypeDef timer_init;
    timer_init.TIM_ClockDivision = TIM_CKD_DIV1;
    timer_init.TIM_CounterMode = TIM_CounterMode_Up;
    timer_init.TIM_Period = 100 -1;//ARR
    timer_init.TIM_Prescaler = 36 -  1; //PSC
    timer_init.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timer_init);
    TIM_OCInitTypeDef oc_init;
    TIM_OCStructInit(&oc_init);
    oc_init.TIM_OCMode = TIM_OCMode_PWM1;
    oc_init.TIM_OCPolarity = TIM_OCPolarity_High;
    oc_init.TIM_OutputState = TIM_OutputState_Enable;
    oc_init.TIM_Pulse = 0; //CCR
    TIM_OC3Init(TIM2, &oc_init);

    TIM_Cmd(TIM2, ENABLE);
}

void set_compare(uint16_t compare){
    TIM_SetCompare3(TIM2, compare);
}