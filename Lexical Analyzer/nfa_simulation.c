#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Data Structures/structures.h"
#include "automata.h"
#include "globals.h"


#define STR_LENGTH 100

static char *error[STR_LENGTH];

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
struct nfa_state *state_construction(int character, struct nfa_state *next_state, struct nfa_state *split_state) {
    struct nfa_state *temp = malloc(sizeof(struct nfa_state));
    temp->character = character;
    temp->next_state = next_state;
    temp->split_state = split_state;

    no_states++;

    return temp;
}

struct fragments create_fragment(struct nfa_state *start, union out_states *out) {
    struct fragments temp = { start, out};
    return temp;
}

void next_state(union out_states *out, struct fragments *fragment) {
    union out_states *temp;

    for (; out; out = temp) {
        temp = out->out;
        out->start = fragment;
    }

}
void concatenation(struct fragments *start, struct fragments *end) {
    next_state(start->pointers, end->start);
    //struct fragments temp = malloc(sizeof(struct fragments));
    struct fragments temp = create_fragment(start->start, end->pointers);
    push(temp);
}

void alternation(struct nfa_state *start, struct nfa_state *end) {}

