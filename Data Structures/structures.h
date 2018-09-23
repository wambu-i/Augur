#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "../Lexical Analyzer/automata.h"

#define MAX_LEN 1000


/* Data Structures */

typedef struct fragments {
    struct nfa_state *start;
    union out_states *pointers;
};

typedef enum errors {
    ERR_FULL,
    ERR_EMPTY
} err;

typedef union out_states {
    struct nfa_state *start;
    union out_states *out;
};

/* Variables */
int stack_pointer;

extern struct fragments states[MAX_LEN];

/* Functions */

void push(struct fragments );

struct fragments pop();

#endif