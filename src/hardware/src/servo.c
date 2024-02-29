#include <pwm.h>

void servo_init(){
    PWM_Init();
}

void servo_setAngle(float angle){
    set_compare(angle / 180 * 2000 + 500);
}