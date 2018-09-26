#ifndef STRUCTURES_H
#define STRUCTURES_H

//#include "automata.h"

#define MAX_LEN 1000


/* Data Structures */
typedef union out_states out_states;
typedef struct fragments fragments;

struct fragments {
    struct nfa_state *start;
    union out_states *pointers;
};

typedef enum errors {
    ERR_FULL,
    ERR_EMPTY
} err;

union out_states {
    struct nfa_state *start;
    union out_states *out;
};

/* Variables */

/* extern fragment fragments; */
extern fragments states[MAX_LEN];

/* Functions */

void push(fragments frag);
fragments pop();

#endif