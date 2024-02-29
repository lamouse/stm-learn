#include <key.h>
#define LOCAL_KEY_GPIO_TYPE_DEF GPIOB
#define LOCAL_KEY_GPIO_PIN GPIO_Pin_10
void Key_Init(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef init;
    init.GPIO_Mode = GPIO_Mode_IPU;
    init.GPIO_Pin = LOCAL_KEY_GPIO_PIN;
    init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LOCAL_KEY_GPIO_TYPE_DEF, &init);
}

uint8_t Key_GetNum()
{
    uint8_t key_num = 0;
    if(GPIO_ReadInputDataBit(LOCAL_KEY_GPIO_TYPE_DEF, LOCAL_KEY_GPIO_PIN) == 0){
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(LOCAL_KEY_GPIO_TYPE_DEF, LOCAL_KEY_GPIO_PIN) == 0)
        {
            Delay_ms(20);
        }
        key_num = 1;
    }
    return key_num;
}