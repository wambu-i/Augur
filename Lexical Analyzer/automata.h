#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <stdio.h>
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

typedef enum re_operands {
    L_PAREN, /*( */
    R_PAREN, /*) */
    CONCAT,
    ALTER, /* | */
    CLOS /* * */
} operands;


/* Function Declaration */
void parse_errors(int type);

nfa_state *state_construction(int , nfa_state *, nfa_state *);

void concatenation(fragments *, fragments *);

void alternation(nfa_state *, nfa_state *);

void kleene_closure(nfa_state *);

void next_state(out_states *, fragments *);

struct fragments create_fragment(nfa_state *start, out_states *out);

void test_nfa();

/* Variables */

int no_states;

static char *digit = "[0-9]";

#endif