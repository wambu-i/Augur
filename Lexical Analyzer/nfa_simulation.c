#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "automata.h"
#include "globals.h"

#define STR_LENGTH 100

static char *error[STR_LENGTH];

char *error_messages {
    "Memory cannot be allocated for the new NFA state",
    "The Regular Expression provided is not valid"
}

errors error_type;

void parse_errors(int type) {
    strcpy(error, error_messages[type]);
    fprintf(stderr, "ERROR: %d : %s", line_number, error);
    exit(EXIT_FAILURE);
}
