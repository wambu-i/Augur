#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyzer.h"
#include <stdbool.h>


static char *reg = "(a|b)*abb";


int is_op(char *ch);


int is_op(char *ch) {
	if((*ch == '|') || (*ch == '/')  || (*ch == '*') || (*ch == '.') || (*ch == '(') || (*ch == ')')) {
		return 1;
    }
	return 0;
}

void pos_test() {
    int nodes;
    struct syntax_tree *buffer;
    char *expr = malloc(sizeof(char) * 100);
    strcpy(expr, augment_re(reg));

    int length = (int) strlen(expr);
    for (int i = 0; i < length; i++) {
        switch (expr[i]) {
            if (!is_op(expr[i])) {
                buffer = create(expr[i], i + 1);
                buffer->nullable = false;

            }
        }

    }

}
