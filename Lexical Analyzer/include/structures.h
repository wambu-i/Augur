#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdbool.h>

#define MAX_LEN 1000


/* Data Structures */
typedef union out_states out_states;
typedef struct fragments fragments;

union out_states {
    struct nfa_state *state;
    union out_states *out;
};


struct fragments {
    struct nfa_state *start;
    out_states *pointers;
};

typedef enum errors {
    ERR_FULL,
    ERR_EMPTY
} err;


/* Variables */

/* extern fragment fragments; */
extern fragments states[MAX_LEN];
char operators[MAX_LEN];

/* Functions */

void push(fragments frag);
bool pop(fragments *);
/* fragments pop(); */

out_states *concate_outs(out_states *a, out_states *b);

void test_pop();



#endif

/*
* An nfa state consists of the character transistion and one or more out states.
* A fragment consists of a partially built nfa without the matching state.
* fragments.start points to the start state
* fragments.out is a list of out states for the fragment.

*/