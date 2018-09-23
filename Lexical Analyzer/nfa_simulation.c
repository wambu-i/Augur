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


void concatenation(struct nfa_state *start, struct nfa_state *end) {
    start->next_state = end->next_state;

}

void alternation(struct nfa_state *start, struct nfa_state *end) {}