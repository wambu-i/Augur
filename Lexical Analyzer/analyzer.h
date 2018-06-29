#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>
#define MAXLINES 5000

extern char *read_lines[MAXLINES];
extern int elements;

int get_input(const char *fp);

int match_language(char *);

void match_include(char *);

void get_firstpos(node *);

void get_nullable(node *);

void get_lastpos(node *);

void get_followpos(node *);

void create_dfa();

void test();

void writelines(char *arr[], int l);

void filecopy(char *ifp);

void add_lexeme(char *letter);

char *augment_re(char *);

struct lexemes *create_new(char *);

struct syntax_tree *create(char, int);

typedef struct node {
	char *lexeme;
	tree *forward;
	tree *previous;
} tree;

typedef struct syntax_tree {
	int nullable;
	int *firstpos;
	int *lastpos;
	int *followpos;
	int position;
	char operation;

	node *left_child;
	node *right_child;
} node;

#endif