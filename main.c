//
// Created by Coney on 25/10/2016.
//

#include <stdio.h>
#include <stdlib.h>

#include "src/state.h"
#include "src/power_state.h"

int main(int argc, char **argv) {
    state_type state = OFF;
    while (1) {
        state = run_state_machine(power_state_table, state);
    }
}