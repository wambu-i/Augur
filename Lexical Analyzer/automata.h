#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <stdio.h>

#define NONE 0
#define START 1
#define END 2

#define EPSILON -1
#define EMPTY -2

/* Data Structures */
typedef struct nfa_state {
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
struct nfa_state *state_construction(int , struct nfa_state *, struct nfa_state *);

void concatenation(struct nfa_state *, struct nfa_state *);

void alternation(struct nfa_state *, struct nfa_state *);

void kleene_closure(struct nfa_state *);

/* Variables */

int no_states;

static char *digit = "[0-9]";

#endif