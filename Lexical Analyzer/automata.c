#include <stdio.h>
#include "automata.h"
#include "globals.h"

char *re_test = "ab";

void test_nfa() {
    struct nfa_state *state1, *state2;
    state1 = state_construction("a", NULL, NULL);
    state2 = state_construction("b", NULL, NULL);
    struct fragments temp1, temp2;

    temp1 = create_fragment(state1, &state1->next_state);
    temp2 = create_fragment(state2, &state2->next_state);

    printf("%s", temp1.start);
}