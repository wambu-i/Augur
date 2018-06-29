#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "analyzer.h"

#define MAX_SIZE 100

struct syntax_tree *create(char op, int pos) {
    struct syntax_tree *new_node = malloc(sizeof(node));
    new_node->operation = op;
    new_node->position = pos;
    new_node->right_child = new_node->left_child = malloc(MAX_SIZE * sizeof(int));
    new_node->lastpos = new_node->firstpos = new_node->followpos =  malloc(MAX_SIZE * sizeof(int));

    return new_node;
}

void get_nullable(node *leaf){
    if (leaf->operation == '*') {
        leaf->nullable = 1;
    }
    else if (leaf->operation == '.') {
        if ((leaf->left_child->nullable == 1) && (leaf->right_child->nullable == 1)) {
            leaf->nullable = 1;
        }
        else {
            leaf->nullable = 0;
        }
    }

    else if (leaf->operation == '|') {
        if ((leaf->left_child->nullable == 1) || (leaf->right_child->nullable == 1)) {
            leaf->nullable = 1;
        }
        else {
            leaf->nullable = 0;
        }
    }
}

void get_firstpos(node *leaf) {
    if (leaf->operation == '*') {
        memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
    }
    else if (leaf->operation == '.') {
        if (leaf->left_child->nullable == 1) {
            memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
            memcpy(leaf->firstpos + MAX_SIZE, leaf->right_child->firstpos, MAX_SIZE * sizeof(int));
        }
        else {
            memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
        }

    }

    else if (leaf->operation == '|') {
        memcpy(leaf->firstpos, leaf->left_child->firstpos, MAX_SIZE * sizeof(int));
        memcpy(leaf->firstpos + MAX_SIZE, leaf->right_child->firstpos, MAX_SIZE * sizeof(int));
    }

}

void get_lastpos(node *leaf) {
    if (leaf->operation == '*') {
        memcpy(leaf->lastpos, leaf->left_child->lastpos, MAX_SIZE * sizeof(int));
    }
    else if (leaf->operation == '.') {
        if (leaf->right_child->nullable == 1) {
            memcpy(leaf->lastpos, leaf->left_child->lastpos, MAX_SIZE * sizeof(int));
            memcpy(leaf->lastpos + MAX_SIZE, leaf->right_child->lastpos, MAX_SIZE * sizeof(int));
        }
        else {
            memcpy(leaf->lastpos, leaf->right_child->lastpos, MAX_SIZE * sizeof(int));
        }

    }

    else if (leaf->operation == '|') {
        memcpy(leaf->firstpos, leaf->left_child->lastpos, MAX_SIZE * sizeof(int));
        memcpy(leaf->firstpos + MAX_SIZE, leaf->right_child->lastpos, MAX_SIZE * sizeof(int));
    }


}

void get_followpos(node *leaf) {
    if (leaf->operation == '.') {
        size_t positions = sizeof(leaf->left_child->lastpos) / sizeof(int);

        for (int i = 0; i < positions; i++) {
           leaf->followpos[leaf->left_child->lastpos[i]] = NULL;
        }
    }

}

char *augment_re(char *expression) {
    strcat(expression, '#');
    return expression;
}