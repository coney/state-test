//
// Created by Coney on 25/10/2016.
//

#include "led.h"

void turn_led(led_type type, led_status status) {
    printf("led%d is %s\n", type, status == LED_ON ? "on" :"off");
}
