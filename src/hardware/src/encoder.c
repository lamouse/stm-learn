#include <encoder.h>


static int16_t encoder_count;
void Encoder_init(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
    GPIO_InitTypeDef init;
    init.GPIO_Mode = GPIO_Mode_IPU;
    init.GPIO_Pin = GPIO_Pin_1| GPIO_Pin_0;
    init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &init);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);

    EXTI_InitTypeDef exti_init;
    exti_init.EXTI_Line = EXTI_Line1 | EXTI_Line0;
    exti_init.EXTI_LineCmd = ENABLE;
    exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
    exti_init.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&exti_init);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef nvic_init;
    nvic_init.NVIC_IRQChannel = EXTI0_IRQn;
    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    nvic_init.NVIC_IRQChannelPreemptionPriority = 1;
    nvic_init.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&nvic_init);
    NVIC_InitTypeDef nvic_init2;
    nvic_init2.NVIC_IRQChannel = EXTI1_IRQn;
    nvic_init2.NVIC_IRQChannelCmd = ENABLE;
    nvic_init2.NVIC_IRQChannelPreemptionPriority = 2;
    nvic_init2.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&nvic_init2);
}

int16_t getEncodeCount(){
    int16_t tmp = encoder_count;
    encoder_count = 0;
    return tmp;
}

void EXTI0_IRQHandler(){
    if(EXTI_GetITStatus(EXTI_Line0) == SET){
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){
            encoder_count--;
        }
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}
void EXTI1_IRQHandler(){
    if(EXTI_GetITStatus(EXTI_Line1) == SET){
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0){
            encoder_count++;
        }
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}