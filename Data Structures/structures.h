#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_LEN 1000

/* Data Structures */

typedef struct fragments {
    struct nfa_state *start;
    int *pointers;
};

typedef enum errors {
    ERR_FULL,
    ERR_EMPTY
} err;

/* Variables */
int stack_pointer;

extern struct fragments states[MAX_LEN];

/* Functions */

void push(struct fragments );

struct fragments pop();

#endif