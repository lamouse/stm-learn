#include <stm32f10x.h>
#include <motor.h>
#include <OLED.h>
#include <delay.h>
#include <key.h>

int main(void){
    OLED_Init();
    //OLED_ShowChar(1, 1, 'A');
    OLED_ShowString(1, 1, "speed");
    Motor_init();
    void Key_Init();
    uint8_t key_num;
    uint16_t key_down_count = 0;
    int8_t seppd = 0;
    while (1)
    {
        key_num = Key_GetNum();

        if(key_num == 1){
            key_down_count++;
            OLED_ShowNum(3, 1, key_down_count, 4);
            seppd += 20;
            if (seppd > 100)
            {
                seppd = -100;
            }
        }

        Motor_SetSpeed(seppd);
        OLED_ShowSignedNum(2, 1, seppd, 3);

    }
}

