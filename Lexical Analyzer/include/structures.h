#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdbool.h>

#define MAX_LEN 1000


/* Data Structures */
typedef union out_states out_states;
typedef union stacks stacks;
typedef struct fragments fragments;
typedef struct nfa_state nfa_state;
typedef struct dfa_state dfa_state;
typedef struct stack stack;

union out_states {
    struct nfa_state *state;
    union out_states *out;
};

union stacks {
    struct nfa_state nfa_stack;
    struct fragments states;
};

struct fragments {
    struct nfa_state *start;
    out_states *pointers;
};

struct nfa_state {
    int character;
    struct nfa_state *next_state;
    struct nfa_state *split_state;
};

struct dfa_state {
    int character;
};
typedef enum errors {
    ERR_ALLOCATE,
    ERR_FULL,
    ERR_EMPTY
} err;


struct stack {
    int top;
    stacks *stack;
};
/* Variables */

/* extern fragment fragments; */
extern fragments states[MAX_LEN];
char operators[MAX_LEN];

/* Functions */
stack *create_stack();
void push(fragments frag);
bool pop(fragments *);

struct nfa_stack *create_nfa_stack();
bool full(stack *stack);
bool empty(stack *stack);
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