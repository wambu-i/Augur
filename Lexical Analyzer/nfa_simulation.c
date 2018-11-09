#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "automata.h"
#include "globals.h"
#include "structures.h"


#define STR_LENGTH 100

static char error[STR_LENGTH];
int line_number;
char *operators;

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
    nfa_state *temp = malloc(sizeof(nfa_state));
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


/* void next_state(out_states *out, fragments *fragment) {
    union out_states *temp;

    for (; out; out = temp) {
        temp = out->out;
        out->start = fragment;
    }

} */
void concatenation(fragments *start, fragments *end) {
    //next_state(start->pointers, end->start);
    //struct fragments temp = malloc(sizeof(struct fragments));
    fragments temp = create_fragment(start->start, end->pointers);
}

/* void alternation(struct nfa_state *start, struct nfa_state *end) {}
 */
bool alternation() {
    fragments frag_1, frag_2;
    if (!pop(&frag_1) || !pop(&frag_2)) {
        printf("Not working.\n");
        return false;
    };
    printf("Working.\n");
    return true;
}


void create_buffers(char *re) {
    int length = strlen(re);
    nfa_state *state;
    fragments frag;
    for (int i = 0; i != length; i++) {
        operands op = re[i];
        switch(op) {
            case UNION: /* '|' operation */
            case CLOSURE: /* Zero or more */
            case CONCATENATION: /* Concantenation */
                operators[i] = op;
                break;
            default:
                state = state_construction(op, NULL, NULL);
                frag = create_fragment(state, state->next_state);
                push(frag);
                break;
        }
    }
}

nfa_state *create_nfa() {
    #define pop() *--operators
    operands op = pop();
    switch(op) {
        case UNION:
            printf("Working!\n");
            break;
        case CLOSURE:
            break;
        case CONCATENATION:
            break;
        default:
            break;
    }
    #undef pop
}