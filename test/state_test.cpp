//
// Created by Coney on 25/10/2016.
//

#include "gmock/gmock.h"

extern "C" {
#include "state.h"
#include "power_state.h"
}


TEST(PowerState, ShouldTurnOnLedWhenPowerOn) {
    run_state_machine(power_state_table, OFF);
}
