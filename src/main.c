#include <stm32f10x.h>
#include <delay.h>
#include <OLED.h>
#include <encoder.h>
int main(void){
    OLED_Init();
    //OLED_ShowChar(1, 1, 'A');
    OLED_ShowString(1, 1, "EXTI IT");
    Encoder_init();
    int16_t count = 0;
    while (1)
    {
         OLED_ShowSignedNum(2, 1, count += getEncodeCount(), 4);
    }
}
