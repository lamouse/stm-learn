#include <stm32f10x.h>
#include <delay.h>
#include <hardware.h>
// #include <buzzer.h>
#include <led.h>
#include <light_sensor.h>
// #include <key.h>
// void led_test();
void buzzer_test();
int main(void){
    buzzer_test();
}


void buzzer_test(){

    uint16_t led1_pin = GPIO_Pin_0;
    uint16_t led2_pin = GPIO_Pin_1;
    GPIO_TypeDef* led_type = GPIOA;
    uint32_t led_rcc = RCC_APB2Periph_GPIOA;
    uint16_t leds_pin = led1_pin | led2_pin;
    GPIO_InitTypeDef led_init;
    led_init.GPIO_Mode = GPIO_Mode_Out_PP;
    led_init.GPIO_Pin = leds_pin;
    led_init.GPIO_Speed = GPIO_Speed_50MHz;
    Hardward_Init(led_rcc, &led_init, led_type);
    LED_OFF(led_type, led1_pin);

    uint32_t light_rcc = RCC_APB2Periph_GPIOB;

    uint16_t light_pin = GPIO_Pin_13;
    GPIO_TypeDef* light_type = GPIOB;
    GPIO_InitTypeDef light_init;
    light_init.GPIO_Mode = GPIO_Mode_IPU;
    light_init.GPIO_Pin = light_pin;
    light_init.GPIO_Speed = GPIO_Speed_50MHz;
    Hardward_Init(light_rcc, &light_init, light_type);

    while(1)
    {
        if(LightSensor_GetNum(light_type, light_pin) == 1){
            LED_OFF(led_type, led2_pin);
            LED_ON(led_type, led1_pin);
        }else{
            LED_OFF(led_type, led1_pin);
            LED_ON(led_type, led2_pin);
        }
    }
}

// void led_test(){
//     uint16_t led1_pin = GPIO_Pin_0;
//     uint16_t led2_pin = GPIO_Pin_1;
//     GPIO_TypeDef* led_type = GPIOA;
//     uint32_t led_rcc = RCC_APB2Periph_GPIOA;
//     uint16_t leds_pin = led1_pin | led2_pin;
//     GPIO_InitTypeDef led_init;
//     led_init.GPIO_Mode = GPIO_Mode_Out_PP;
//     led_init.GPIO_Pin = leds_pin;
//     led_init.GPIO_Speed = GPIO_Speed_50MHz;
//     Hardward_Init(led_rcc, &led_init, led_type);
//     LED_OFF(led_type, leds_pin);

//     uint32_t key_rcc = RCC_APB2Periph_GPIOB;
//     uint16_t key1_pin = GPIO_Pin_1;
//     uint16_t key2_pin = GPIO_Pin_11;
//     uint16_t keys_pin = key1_pin | key2_pin;
//     GPIO_TypeDef* key_type = GPIOB;
//     GPIO_InitTypeDef key_init;
//     key_init.GPIO_Mode = GPIO_Mode_IPU;
//     key_init.GPIO_Pin = keys_pin;
//     key_init.GPIO_Speed = GPIO_Speed_50MHz;
//     Hardward_Init(key_rcc, &key_init, key_type);

//     while(1)
//     {
//         uint8_t key1_num = Key_GetNum(key_type, key1_pin);
//         uint8_t key2_num = Key_GetNum(key_type, key2_pin);
//         if (key1_num){
//             LED_Turn(led_type, led1_pin);
//         }
//         if(key2_num){
//             LED_Turn(led_type, led2_pin);
//         }
//         // LED_OFF(led_type, led2_pin);
//         // Delay_s(1);
//         // LED_OFF(led_type, led1_pin);
//         // LED_ON(led_type, led2_pin);
//         // Delay_s(1);
//     }
// }