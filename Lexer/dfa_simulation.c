/*
* Creates a deterministic finite automata from a a non-deterministic
* finite automata using the Subset construction algorithm.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <automata.h>
#include <structures.h>

#define ELEMENTS(arr) sizeof(arr)/sizeof(arr[0])

nfa_state stack[MAX_LEN];
/* fragments closure[MAX_LEN];*/

/*
* The epsilon closure is the set of states that can be reached using epsilon transitions
* only.
* get_epsilon_closure returns a set of NFA states that can be reached from a start
* state only on epsilon transitions alone.
*/

void get_epsilon_closure(nfa_state *state) {
    nfa_state *pointer;
    pointer = stack;
    int empty_stack;

    nfa_state *closure = malloc(sizeof(nfa_state) * MAX_LEN);

    if (!closure)
        return;

    closure = state;

    #define push_state(state) *pointer++ = state
    #define pop_state() *(--pointer)
    #define empty() empty_stack = pop_state()

    nfa_state *temp = state;
    nfa_state popped;


    while (temp != NULL) {
        push_state(*temp);
        bool split = (temp->character == 256);
        if (split) {
            nfa_state *split_temp = temp->split_state;
            while (split_temp) {
                bool match = (split_temp->character == 257);
                if (match) {
                    break;
                }
                push_state(*split_temp);
                split_temp = split_temp->next_state;
            }

            temp = temp->next_state;

        }
        else {
            temp = temp->next_state;
        }
    }

    while (true) {
        popped = pop_state();
        if (!popped)
            return;
    }

    #undef pop_state
    #undef push_state
}

