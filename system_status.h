//
// Created by Coney on 25/10/2016.
//

#ifndef STATE_TEST_SYSTEM_STATUS_H
#define STATE_TEST_SYSTEM_STATUS_H

int is_system_fault();

int need_power_on();

int need_power_off();

void boot_up();

void shut_down();

void report_fault();

void do_things();

#endif //STATE_TEST_SYSTEM_STATUS_H
