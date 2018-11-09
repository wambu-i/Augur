#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "analyzer.h"
#include "globals.h"

int elements;

struct node *head = NULL;

void test() {
    for (int i = 0; i < elements; i++){
        match_language(read_lines[i]);
    }
}

void add_lexeme(char *letter) {
    struct node *buffer = head;
    struct node *character = create_new(letter);
    if (head == NULL) {
        head = character;
    }
    while (buffer->forward != NULL) {
        buffer = buffer->forward;
        buffer->forward = character;
        character->previous = buffer;
    }
}

struct lexemes *create_new(char *word) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->lexeme = word;
    new_node->forward = NULL;
    new_node->previous = NULL;
    return new_node;
}
