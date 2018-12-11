#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <structures.h>

#define STR_LENGTH 100
#define TOP -1


static char error[STR_LENGTH];
static int stack_pointer;
fragments states[MAX_LEN];

static char *error_messages[] =  {
    "Cannot allocate required memory.",
    "Cannot push onto the stack. The stack is full.",
    "Cannot pop from the stack. The stack is empty."
};

stack *create_stack() {
    stack *stack = malloc(sizeof(*stack));
    if (!stack) {
        strcpy(error, error_messages[ERR_ALLOCATE]);
        fprintf(stderr, error);
        exit(EXIT_FAILURE);
    }
    stack->top = TOP;
    stack->stack = malloc(sizeof(*stack->stack) * MAX_LEN);
    if (!stack->stack) {
        strcpy(error, error_messages[ERR_ALLOCATE]);
        fprintf(stderr, error);
        exit(EXIT_FAILURE);
    }
    return stack;
}

bool full(stack *stack) {
    return (stack->top == MAX_LEN - 1);
}

bool empty(stack *stack) {
    return (stack->top == -1);
}

void push_states(struct nfa_stack *stack, nfa_state *state) {
    if (full(stack)) {
        strcpy(error, error_messages[ERR_FULL]);
        fprintf(stderr, error);
        exit(EXIT_FAILURE);
    }
    else {

    }
}

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
    printf("%d\n", stack_pointer);
}

void push_states(nfa_state state) {

}

out_states *concate_outs(out_states *a, out_states *b) {
    /* Concatenate two lists of out pointers
    * that point to out states of an NFA state
    */
   out_states *temp = a;
   while (a->out) {
       a = a->out;
   }
   a->out = b;
   return temp;
}