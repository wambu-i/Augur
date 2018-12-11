#ifndef ERRORS_H
#define ERRORS_H

/*
Provides various errors that can be encountered when constructing lexer.
All errors lead to a program failure.
*/

typedef enum errors {
    ERR_ALLOCATE,
    ERR_FULL,
    ERR_EMPTY,
    ERR_UNKNOWN,
    ERR_MEM, /* No memory available */
    ERR_EXPR /* Bad regular expression provided */
} err;

char *error_messages[] =  {
    "Cannot allocate required memory.\n",
    "Cannot push onto the stack. The stack is full.\n",
    "Cannot pop from the stack. The stack is empty.\n",
    "Unknown stack type. Not pushing onto stack.\n",
    "Memory cannot be allocated for the new NFA state.\n",
    "The Regular Expression provided is not valid.\n"
};


#endif