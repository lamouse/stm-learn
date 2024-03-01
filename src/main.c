#include <stm32f10x.h>
#include <encoder.h>
#include <OLED.h>
#include <delay.h>
#include <timer.h>

int16_t count = 0;
int main(void){
	/*模块初始化*/
	OLED_Init();		//OLED初始化
    TIM_Ecoder_init();
    Timer_Init();
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "speed:");		//1行1列显示字符串Freq:00000Hz
    OLED_ShowString(2, 1, "angle:");		//1行1列显示字符串Freq:00000Hz

	/*使用PWM模块提供输入捕获的测试信号*/
	while (1)
	{
		OLED_ShowSignedNum(1, 7, count, 5);
        OLED_ShowSignedNum(2, 7, count * 4.5, 5);
	}
}

void TIM2_IRQHandler(void){
    if(TIM_GetFlagStatus(TIM2, TIM_IT_Update) == SET){
        count = TIM_Encoder_get();
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
