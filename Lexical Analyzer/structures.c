#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

#define STR_LENGTH 100


static char error[STR_LENGTH];
static int stack_pointer;
fragments states[MAX_LEN];

static char *error_messages[] =  {
    "Cannot push onto the stack. The stack is full.",
    "Cannot pop from the stack. The stack is empty."
};


void push(fragments frag) {
    /*printf("%d\n", stack_pointer );*/
    if (stack_pointer > MAX_LEN - 1) {
        strcpy(error, error_messages[ERR_FULL]);
        printf("%s", error);
    }
    else {
        printf("Pushing.\n");
        states[stack_pointer++] = frag;
        //printf("%d\n", stack_pointer);
    }
}

void test_pop() {
    if (stack_pointer > 0) {
        printf("Popping - %d\n", --stack_pointer);
    }
    else {
        ;
    }
}

bool pop(fragments *frag) {
    if (stack_pointer > 0) {
        *frag =  states[--stack_pointer];
        return true;
    }
    else {
        strcpy(error, error_messages[2]);
        printf("%s", error);
        return false;
    }

}
/* fragments pop() {
    if (stack_pointer > 0) {
        //printf("%d\n", stack_pointer);
        return states[--stack_pointer];
    }
    else {
        strcpy(error, error_messages[2]);
        printf("%s", error);
        //fragments temp = NULL;
        return states[0];
    }
} */

out_states *concate_outs(out_states a, out_states b) {
    /* Concatenate two lists of out pointers
    * that point to out states of an NFA state
    */

}