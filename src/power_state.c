//
// Created by Coney on 25/10/2016.
//

#include <stdbool.h>
#include "power_state.h"
#include "led.h"
#include "system_status.h"


// POWER ON
static void power_on_entry() {
    turn_led(POWER_LED, ON);
}

static void power_on_exit() {
    // do nothing
}

static state_type power_on_guard() {
    if (is_system_fault()) {
        return FAULT;
    } else {
        return RUNNING;
    }
}


static void power_on_run() {
    boot_up();
}

// POWER OFF
static void power_off_entry() {
    turn_led(POWER_LED, LED_OFF);
}

static void power_off_exit() {
    // do nothing
}

static state_type power_off_guard() {
    if (need_power_on()) {
        return ON;
    } else {
        return OFF;
    }
}

static void power_off_run() {
    shut_down();
}

// POWER FAULT
static void power_fault_entry() {
    turn_led(FAULT_LED, LED_ON);
}

static void power_fault_exit() {
    turn_led(FAULT_LED, LED_OFF);
}

static state_type power_fault_guard() {
    if (is_system_fault()) {
        return FAULT;
    }  else {
        return ON;
    }
}

static void power_fault_run() {
    report_fault();
}

// POWER RUNNING
static void power_running_entry() {
    turn_led(RUNNING_LED, LED_ON);
}

static void power_running_exit() {
    turn_led(RUNNING_LED, LED_OFF);
}

static state_type power_running_guard() {
    if (need_power_off()) {
        return OFF;
    } else if (is_system_fault()) {
        return FAULT;
    } else {
        return RUNNING;
    }
}

static void power_running_run() {
    do_things();
}


state_table power_state_table[STATE_TYPE_COUNT] = {
        {power_on_entry,      power_on_exit,      power_on_guard,      power_on_run},
        {power_off_entry,     power_off_exit,     power_off_guard,     power_off_run},
        {power_running_entry, power_running_exit, power_running_guard, power_running_run},
        {power_fault_entry,   power_fault_exit,   power_fault_guard,   power_fault_run}
};



