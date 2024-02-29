#include <stm32f10x.h>
#include <delay.h>
#include <OLED.h>
#include <EXTI_interrupt.h>
int main(void){
    OLED_Init();
    //OLED_ShowChar(1, 1, 'A');
    OLED_ShowString(1, 1, "EXTI IT");
    EXTI_Inint();
    while (1)
    {
         OLED_ShowSignedNum(2,1, EXTI_CountGet(), 2);
    }
}
