//
// Created by Coney on 25/10/2016.
//

#ifndef STATE_TEST_STATE_H
#define STATE_TEST_STATE_H

#include <stddef.h>

typedef enum tag_state_type {
    ON,
    OFF,
    RUNNING,
    FAULT,
    STATE_TYPE_COUNT
} state_type;

typedef struct tag_state_table {
    void (*entry)();
    void (*exit)();
    state_type (*guard)();
    void (*run)();
} state_table;


state_type run_state_machine(state_table *table, state_type initial_state);

#endif //STATE_TEST_STATE_H
