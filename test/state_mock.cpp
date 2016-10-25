#include "state_mock.h"


IMPLEMENT_FUNCTION_MOCK0(IsSystemFaultMock, is_system_fault, int ());
IMPLEMENT_FUNCTION_MOCK0(NeedPowerOnMock, need_power_on, int ());
IMPLEMENT_FUNCTION_MOCK0(NeedPowerOffMock, need_power_off, int ());

IMPLEMENT_FUNCTION_MOCK0(BootUpMock, boot_up, void ());
IMPLEMENT_FUNCTION_MOCK0(ShutDownMock, shut_down, void ());
IMPLEMENT_FUNCTION_MOCK0(ReportFaultMock, report_fault, void ());
IMPLEMENT_FUNCTION_MOCK0(DoThingsMock, do_things, void ());

IMPLEMENT_FUNCTION_MOCK2(TurnLedMock, turn_led, void (led_type, led_status));
