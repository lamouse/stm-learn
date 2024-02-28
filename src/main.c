#include <stm32f10x.h>
#include <delay.h>
#include <OLED.h>
int main(void){
    OLED_Init();
    OLED_ShowChar(1, 1, 'A');
    OLED_ShowString(1, 3, "HELLO word");
    OLED_ShowSignedNum(2,1, -12, 2);
    OLED_ShowBinNum(3,1, 0xaaa5, 16);
    while (1)
    {
    }
}
