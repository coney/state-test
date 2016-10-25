//
// Created by Coney on 25/10/2016.
//

#include "state.h"


state_type run_state_machine(state_table *table, state_type initial_state) {
    state_table *current_state = table + initial_state;
    state_type new_state = current_state->guard();
    if (new_state != initial_state) {
        current_state->exit();
        current_state = table + new_state;
        current_state->entry();
    }
    current_state->run();
    return new_state;
}
