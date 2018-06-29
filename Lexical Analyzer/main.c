#include <stdio.h>
#include <stdlib.h>
#include "analyzer.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Please provide a valid source code file.\n");
        exit(EXIT_FAILURE);
    }
    else {
        get_input(*(++argv));
    }
    return 0;
}