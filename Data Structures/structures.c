#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

#define STR_LENGTH 100

static char *error[STR_LENGTH];


stack_pointer = 0;

char *error_messages =  {
    "Cannot push onto the stack. The stack is full.",
    "Cannot pop from the stack. The stack is empty."
};


void push(struct fragments frag) {
    if (stack_pointer > MAX_LEN) {
        strcpy(error, error_messages[ERR_FULL]);
        printf("%s", error);
    }
    else {
        states[stack_pointer++] = frag;
    }
}

struct fragments pop() {
    if (stack_pointer > 0) {
        return states[--stack_pointer];
    }
    else {
        strcpy(error, error_messages[2]);
        printf("%s", error);
        return;
    }
}