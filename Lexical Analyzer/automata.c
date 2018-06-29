#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "analyzer.h"

#define MAX_SIZE 100


struct syntax_tree *create(char *reg, int pos) {
    struct syntax_tree *new_node = malloc(sizeof(struct syntax_tree));
    new_node->regex = reg;
    new_node->position = pos;
    new_node->right_child = new_node->left_child = malloc(MAX_SIZE * sizeof(int));
    new_node->lastpos = new_node->firstpos = new_node->followpos =  malloc(MAX_SIZE * sizeof(int));

    return new_node;
}

void get_nullable(struct syntax_tree *leaf, char *operation){
    /* nullable(n) is true for a syntax-tree node n if and only if the subexpression
    represented by n has E in its language. */

    if (operation == "*") {
        leaf->nullable = 1;
    }
    else if (operation == ".") {
        if ((leaf->left_child->nullable == 1) && (leaf->right_child->nullable == 1)) {
            leaf->nullable = 1;
        }
        else {
            leaf->nullable = 0;
        }
    }

    else if (operation == "|") {
        if ((leaf->left_child->nullable == 1) || (leaf->right_child->nullable == 1)) {
            leaf->nullable = 1;
        }
        else {
            leaf->nullable = 0;
        }
    }
    else {
        ;
    }
}

void get_firstpos(struct syntax_tree *leaf, char *operation) {
    /*firstpos(n) is the set of positions in the subtree rooted at n that corre­spond
    to the first symbol of at least one string in the language of the
    subexpression rooted at n. */

    if (operation == "*") {
        memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
    }
    else if (operation == ".") {
        if (leaf->left_child->nullable == 1) {
            memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
            memcpy(leaf->firstpos + MAX_SIZE, leaf->right_child->firstpos, MAX_SIZE * sizeof(int));
        }
        else {
            memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
        }

    }

    else if (operation == "|") {
        memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
        memcpy(leaf->firstpos + MAX_SIZE, leaf->right_child->firstpos, MAX_SIZE * sizeof(int));
    }

    else {
        ;
    }

}

void get_lastpos(struct syntax_tree  *leaf, char *operation) {
    /*lastpos(n) is the set of positions in the subtree rooted at n that corre­spond
    to the last symbol of at least one string in the language of the
    sub expression rooted at n.*/

    if (operation == "*") {
        memcpy(leaf->lastpos, leaf->left_child->lastpos, MAX_SIZE * sizeof(int));
    }
    else if (operation == ".") {
        if (leaf->right_child->nullable == 1) {
            memcpy(leaf->lastpos, leaf->left_child->lastpos, MAX_SIZE * sizeof(int));
            memcpy(leaf->lastpos + MAX_SIZE, leaf->right_child->lastpos, MAX_SIZE * sizeof(int));
        }
        else {
            memcpy(leaf->lastpos, leaf->right_child->lastpos, MAX_SIZE * sizeof(int));
        }

    }

    else if (operation == "|") {
        memcpy(leaf->firstpos, leaf->left_child->lastpos, MAX_SIZE * sizeof(int));
        memcpy(leaf->firstpos + MAX_SIZE, leaf->right_child->lastpos, MAX_SIZE * sizeof(int));
    }

    else {
        ;
    }


}

void get_followpos(struct syntax_tree  *leaf, char *operation) {
    if (operation == ".") {
        size_t positions = sizeof(leaf->left_child->lastpos) / sizeof(int);

        for (int i = 0; i < positions; i++) {
           memcpy(leaf->followpos[i], leaf->right_child->firstpos, MAX_SIZE * sizeof(int));
        }
    }
    else if (operation == "*") {
        size_t positions = sizeof(leaf->lastpos) / sizeof(int);
        for (int i = 0; i < positions; i++) {
           memcpy(leaf->followpos[i], leaf->firstpos, MAX_SIZE * sizeof(int));
        }
    }
}

char *augment_re(char *expression) {
    char *buffer = malloc(sizeof(char) * MAX_SIZE);
    strcat(buffer, expression);
    strcat(buffer, "#");
    return buffer;
}