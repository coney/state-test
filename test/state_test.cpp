//
// Created by Coney on 25/10/2016.
//

#include "gmock/gmock.h"

extern "C" {
#include "state.h"
#include "power_state.h"
}

#include "state_mock.h"
#include "../gmock/cmock/cmock.h"
#include "../gmock/gtest/gtest.h"
#include "../src/state.h"
#include "../src/power_state.h"
#include "../gmock/gmock/gmock.h"
#include "../src/led.h"
#include "../src/system_status.h"

using namespace testing;


class PowerStateTest : public Test {
protected:
    void SetUp() {
        state = OFF;
        EXPECT_FUNCTION_CALL(isSystemFault, ()).WillRepeatedly(Return(FALSE));
    }

    void TearDown() {
        // do cleanup
    }

    NeedPowerOnMock powerOn;
    TurnLedMock led;
    BootUpMock bootUp;
    DoThingsMock doThings;
    IsSystemFaultMock isSystemFault;
    state_type state;
};

TEST_F(PowerStateTest, ShouldTurnOnLedWhenPowerOn) {
    EXPECT_FUNCTION_CALL(powerOn, ()).WillOnce(Return(TRUE));
    EXPECT_FUNCTION_CALL(led, (POWER_LED, LED_ON)).Times(1);
    EXPECT_FUNCTION_CALL(bootUp, ()).Times(1);
    state = run_state_machine(power_state_table, state);
    ASSERT_EQ(ON, state);

    EXPECT_FUNCTION_CALL(led, (RUNNING_LED, LED_ON)).Times(1);
    EXPECT_FUNCTION_CALL(doThings, ()).Times(1);
    state = run_state_machine(power_state_table, state);
    ASSERT_EQ(RUNNING, state);

    EXPECT_FUNCTION_CALL(isSystemFault, ()).WillOnce(Return(TRUE));
    EXPECT_FUNCTION_CALL(led, (RUNNING_LED, LED_OFF)).Times(1);
    EXPECT_FUNCTION_CALL(led, (FAULT_LED, LED_ON)).Times(1);
    state = run_state_machine(power_state_table, state);
    ASSERT_EQ(FAULT, state);
}
