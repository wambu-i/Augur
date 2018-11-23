#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "structures.h"

#define NONE 0
#define START 1
#define END 2

#define EPSILON -1
#define EMPTY -2


/* Data Structures */
typedef struct nfa_state nfa_state;

struct nfa_state {
    int character;
    struct nfa_state *next_state;
    struct nfa_state *split_state;
};

/*
Provides various errors that can be encountered when constructing the NFA.
All errors lead to a program failure.
*/

typedef enum error_states {
    ERR_MEM, /* No memory available */
    ERR_EXPR /* Bad regular expression provided */

} errors;

typedef enum {
    CONCATENATION = '.',
    UNION = '|',
    CLOSURE = '*',
    LEFT_P = '(',
    RIGHT_P = ')',
    LEFT_SB = '[',
    RIGHT_SB = ']'
} operands;

typedef enum {
    split = 256,
    match = 257
} state;

/* Function Declaration */
void parse_errors(int type);

bool create_buffers(char *);

nfa_state *state_construction(int , nfa_state *, nfa_state *);

void concatenation(fragments *, fragments *);

bool alternation();

void kleene_closure(nfa_state *);

void next_state(out_states *, fragments *);

struct fragments create_fragment(nfa_state *start, out_states *out);

char *create_postfix(char *);

nfa_state *create_nfa();

void create_match_state(nfa_state *, out_states *);
out_states* flatten(nfa_state **outp);

/* Variables */

int no_states;
fragments fragment;

#endif