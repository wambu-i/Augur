#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>
#define MAXLINES 5000

extern char *read_lines[MAXLINES];
extern int elements;

void get_input(const char *fp);

int match_language(char *);

void match_include(char *);

void create_nfa();

void create_dfa();

void test();

void writelines(char *arr[], int l);

void filecopy(char *ifp);

void add_lexeme(char *letter);

struct lexemes *create_new(char *);

typedef struct node {
	char *lexeme;
	struct node *forward;
	struct node *previous;
};

#endif