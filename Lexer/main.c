#include <stdio.h>
#include <stdlib.h>
#include <automata.h>

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
    nfa_state *result = create_nfa();
    printf("Beginning - %d\n", result->character);
    //get_epsilon_closure(result);
    return 0;
  
}
