#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyzer.h"
#include <stdbool.h>

#define MAX_SIZE 100


static char *reg = "(a|b)*abb";


bool is_op(char ch);


bool is_op(char ch) {
	if((ch == '|') || (ch == '/')  || (ch == '*') || (ch == '.') || (ch == '(') || (ch == ')')) {
		return true;
    }
	return false;
}

void pos_test() {
    int nodes;
    struct syntax_tree *stack[MAX_SIZE];
    struct syntax_tree *buffer;
    char *expr = malloc(sizeof(char) * 100);
    strcpy(expr, augment_re(reg));

    int length = (int) strlen(expr);
    for (int i = 0; i < length; i++) {
        if (!is_op(expr[i])) {
            printf("%s\n", &expr[i]);
            nodes++;
            buffer = create(&expr[i], nodes);
            buffer->nullable = false;
        }

        else if(expr[i] == '*') {
            buffer = create(&expr[i], 0);
            get_nullable(buffer, "*");
            buffer->position = 3;
            printf("%d", buffer->position);
            //get_firstpos(buffer, '*');
            //get_lastpos(buffer, '*');
            //get_followpos(buffer, '*');
        }
       // *stack[i] = *buffer;
        //printf("%d", (*stack[i]).nullable);
        printf("%d", buffer->position);
    }

}
