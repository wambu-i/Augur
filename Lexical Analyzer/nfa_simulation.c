#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "automata.h"
#include "globals.h"
#include "structures.h"


#define STR_LENGTH 100

static char error[STR_LENGTH];
int line_number;

char *error_messages =  {
    "Memory cannot be allocated for the new NFA state",
    "The Regular Expression provided is not valid"
};

errors error_type;

void parse_errors(int type) {
    strcpy(error, error_messages[type]);
    fprintf(stderr, "ERROR: %d : %s", line_number, error);
    exit(EXIT_FAILURE);

}
/* Create an nfa state */
nfa_state *state_construction(int character, nfa_state *next_state, nfa_state *split_state) {
    nfa_state *temp = malloc(sizeof(nfa_state));
    temp->character = character;
    temp->next_state = next_state;
    temp->split_state = split_state;

    no_states++;

    return temp;
}

fragments create_fragment(nfa_state *start, out_states *out) {
    fragments temp = { start, out};
    return temp;
}

void next_state(out_states *out, fragments *fragment) {
    union out_states *temp;

    for (; out; out = temp) {
        temp = out->out;
        out->start = fragment;
    }

}
void concatenation(fragments *start, fragments *end) {
    next_state(start->pointers, end->start);
    //struct fragments temp = malloc(sizeof(struct fragments));
    fragments temp = create_fragment(start->start, end->pointers);
    push(temp);
}

void alternation(struct nfa_state *start, struct nfa_state *end) {}

