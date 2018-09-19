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
    int label;
    char *accepting_state;
    int anchored;

    struct nfa_state *next_state;
    struct nfa_state *empty_transitions;

};

/* Provides various errors that can be encountered when constructing the NFA.
All errors lead to a program failure.*/

typedef enum error_states {
    ERR_MEM, /* No memory available */
    ERR_EXPR /* Bad regular expression provided */

} errors;

/* Function Declaration */
void parse_errors(int type);
struct nfa_state thompson_construction(struct nfa_state *);


#endif