/*
* Create's non-deterministic finite automata regular expressions
* using Thompson's algorithm.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <automata.h>
#include <globals.h>
#include <structures.h>


#define STR_LENGTH 100

static char error[STR_LENGTH];
int line_number;
char operators[MAX_LEN];
static char *operator;
nfa_state match_state = { match };

char *error_messages[] =  {
    "Memory cannot be allocated for the new NFA state",
    "The Regular Expression provided is not valid"
};

errors error_type;

void parse_errors(int type) {
    strcpy(error, error_messages[type]);
    fprintf(stderr, "ERROR: %d : %s", line_number, error);
    exit(EXIT_FAILURE);

}

nfa_state *state_construction(int character, nfa_state *next_state, nfa_state *split_state) {
    /* Create an nfa state
    * An NFA state consists of the transition character, the next state, and
    * a split state if there is more than one next state
     */
    nfa_state *temp = malloc(sizeof(nfa_state *));
    temp->character = character;
    temp->next_state = next_state;
    temp->split_state = split_state;

    no_states++;

    return temp;
}

fragments create_fragment(nfa_state *start, out_states *out) {
    /*
    * A fragment is a partial NFA
    * temp.start is the start state
    * temp.out is the out states of the NFA
    */
    fragments temp = { start, out};
    /* printf("Chara - %c \n", temp.start->character); */
    return temp;
}


bool alternation() {
    fragments frag_A, frag_B;
    if (!pop(&frag_B) || !pop(&frag_A))
        return false;

    nfa_state *temp = state_construction(epsilon, frag_A.start, frag_B.start);
    fragment = create_fragment(temp, concate_outs(frag_A.pointers, frag_B.pointers));
    push(fragment);

    return true;
}

bool create_buffers(char *re) {
    int length = strlen(re);
    operator = operators;
    nfa_state *state;
    fragments frag;

    #define push_op(s) *operator++ = s

    for (int i = 0; i != length; i++) {
        operands op = re[i];
        switch(op) {
            case UNION: /* '|' operation */
            case CLOSURE: /* Zero or more */
            case CONCATENATION: /* Concantenation */
                push_op((char) op);
                *operator = (char) op;
                break;
            default:
                state = state_construction(op, NULL, NULL);
                frag = create_fragment(state, flatten(&state->next_state));
                push(frag);
                break;
        }
    }

    if (operator != operators) {
        return false;
    }
    return true;
    #undef push_op
}

nfa_state *create_nfa() {
    fragments frag;
    #define pop_op() *(--operator)
    operands op = pop_op();
    switch(op) {
        case UNION:
            alternation();
            break;
        case CLOSURE:
            break;
        case CONCATENATION:
            break;
        default:
            break;
    }
    pop(&frag);
    if (operator != operators) {
        return NULL;
    }
    create_match_state(&match_state, frag.pointers);
    return frag.start;
    #undef pop_op
}

void create_match_state(nfa_state *state, out_states *out) {
    /* Points the dangling arrows of the last state
    * to the matching state.
    */
    out_states *temp;

    while (out) {
        temp = out->out;
        out->state = state;
        out = temp;
    }
}

out_states* flatten(nfa_state **out) {
	out_states *temp;

	temp = (out_states*)out;
	temp->out = NULL;
	return temp;
}