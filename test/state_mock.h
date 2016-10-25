//
// Created by Coney on 25/10/2016.
//

#ifndef SYSTEM_STATUS_MOCK_H
#define SYSTEM_STATUS_MOCK_H

#include <cmock/cmock.h>

extern "C" {
#include "system_status.h"
#include "led.h"
}

int is_system_fault();

int need_power_on();

int need_power_off();

void boot_up();

void shut_down();

void report_fault();

void do_things();
void turn_led(led_type type, led_status status);


DECLARE_FUNCTION_MOCK0(IsSystemFaultMock, is_system_fault, int ());
DECLARE_FUNCTION_MOCK0(NeedPowerOnMock, need_power_on, int ());
DECLARE_FUNCTION_MOCK0(NeedPowerOffMock, need_power_off, int ());

DECLARE_FUNCTION_MOCK0(BootUpMock, boot_up, void ());
DECLARE_FUNCTION_MOCK0(ShutDownMock, shut_down, void ());
DECLARE_FUNCTION_MOCK0(ReportFaultMock, report_fault, void ());
DECLARE_FUNCTION_MOCK0(DoThingsMock, do_things, void ());

DECLARE_FUNCTION_MOCK2(TurnLedMock, turn_led, void (led_type, led_status));


#endif //SYSTEM_STATUS_MOCK_H
