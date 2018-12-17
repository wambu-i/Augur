#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errors.h>
#include <structures.h>


#define STR_LENGTH 100
#define TOP -1


static char error[STR_LENGTH];
static int stack_pointer;
fragments states[MAX_LEN];


stack *create_stack(types type) {
    stack *new = malloc(sizeof(*new));
    if (!new) {
        strcpy(error, error_messages[ERR_ALLOCATE]);
        fprintf(stderr, "%s", error);
        exit(EXIT_FAILURE);
    }
    
    new->top = TOP;
    new->type = type;
    new->stack = malloc(sizeof(*new->stack) * MAX_LEN);
    if (!new->stack) {
        free(new);
        strcpy(error, error_messages[ERR_ALLOCATE]);
        fprintf(stderr, "%s", error);
        exit(EXIT_FAILURE);
    }
    return new;
}

bool full(stack *stack) {
    return (stack->top == MAX_LEN - 1);
}

bool empty(stack *stack) {
    return (stack->top == -1);
}

void push(stack *stack, ...) {
    va_list args;
    va_start(args, stack);

    if (stack->top == MAX_LEN - 1) {
        strcpy(error, error_messages[ERR_FULL]);
        fprintf(stderr, "%s", error);
        exit(EXIT_FAILURE);
    }
    switch (stack->type) {
        case FRAGMENTS:
            stack->stack[stack->top++].states = va_arg(args, fragments *);
            break;
        case STATES:
            stack->stack[stack->top++].nfa_stack = va_arg(args, nfa_state *);
            break;
        default:
            strcpy(error, error_messages[ERR_UNKNOWN]);
            fprintf(stderr, "%s", error);
            exit(EXIT_FAILURE);
    }
    va_end(args);
}

/* Void pointer because it can be cast into any desired pointer.*/
bool pop(stack *stack, void *element) {
    bool popped = false;
    if (stack->top == -1) {
        strcpy(error, error_messages[ERR_EMPTY]);
        fprintf(stderr, "%s", error);
        exit(EXIT_FAILURE);
    }
    switch (stack->type) {
        case FRAGMENTS:
            printf("Popping element %d\n", stack->top);
            *((fragments *) element) = *stack->stack[--stack->top].states;
            popped = true;
            break;
        case STATES:
            element = stack->stack[--stack->top].nfa_stack;
            popped = true;
            break;
        default:
            strcpy(error, error_messages[ERR_UNKNOWN]);
            fprintf(stderr, "%s", error);
            exit(EXIT_FAILURE);
    }
    return popped;
}

void t_push(fragments frag) {
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

bool t_pop(fragments *frag) {
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