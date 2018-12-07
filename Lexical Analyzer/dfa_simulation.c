/*
* Creates a deterministic finite automata from a a non-deterministic
* finite automat using the Subset construction algorithm.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <automata.h>
#include <structures.h>

nfa_state stack[MAX_LEN];
fragments closure[MAX_LEN];

void get_epsilon_closure(nfa_state *state) {
    nfa_state *pointer;
    pointer = stack;

    #define push_state(state) *pointer++ = state
    #define pop_state() *(--pointer)

}