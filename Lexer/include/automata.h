#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "structures.h"


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
    epsilon = 256,
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

void get_epsilon_closure(nfa_state *);

void move();

/* Variables */

int no_states;
fragments fragment;

#endif
