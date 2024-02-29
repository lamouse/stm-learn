#include <stm32f10x.h>
#include <pwm.h>
#include <OLED.h>
#include <delay.h>

int main(void){
    //OLED_Init();
    //OLED_ShowChar(1, 1, 'A');
    //OLED_ShowString(1, 1, "TIME COUNT");
    PWM_Init();
    uint8_t i = 0;
    while (1)
    {
        for (i = 0; i < 100; i++)
        {
            set_compare(i);
            Delay_ms(10);
        }

        for (i = 0; i < 100; i++)
        {
            set_compare(100 - i);
            Delay_ms(10);
        }
    }
}

