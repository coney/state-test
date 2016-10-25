//
// Created by Coney on 25/10/2016.
//

#ifndef STATE_TEST_LED_H
#define STATE_TEST_LED_H

#include <stdio.h>

typedef enum tag_led_type {
    POWER_LED,
    RUNNING_LED,
    FAULT_LED
} led_type;

typedef enum tag_led_status {
    LED_ON,
    LED_OFF
} led_status;

void turn_led(led_type type, led_status status);

#endif //STATE_TEST_LED_H
