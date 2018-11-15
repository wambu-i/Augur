#include <stdio.h>
#include <stdlib.h>
#include "analyzer.h"
#include "automata.h"

int main(int argc, char *argv[]) {
    /*if (argc == 1) {
        printf("Please provide a valid source code file.\n");
        exit(EXIT_FAILURE);
    }
    else {
        get_input(*(++argv));
    }*/
    //match_language("This is a line");
    char *_test = "a|b";
    create_buffers(_test);
    create_nfa();
    return 0;
  
}
