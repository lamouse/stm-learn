#include <stm32f10x.h>
#include <servo.h>
#include <OLED.h>
#include <delay.h>
#include <key.h>

int main(void){
    OLED_Init();
    //OLED_ShowChar(1, 1, 'A');
    OLED_ShowString(1, 1, "angle");
    servo_init();
    void Key_Init();
    uint8_t key_num = 0;

    float angle = 0.f;
    while (1)
    {
        key_num = Key_GetNum();

        if(key_num == 1){
            OLED_ShowNum(3, 1, key_num, 3);
            angle += 30;
            if (angle > 180)
            {
                angle = 0;
            }

            servo_setAngle(angle);
        }
        OLED_ShowNum(2, 1, angle, 3);

    }
}

