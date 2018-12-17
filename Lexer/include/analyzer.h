#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>
#define MAXLINES 5000

extern char *read_lines[MAXLINES];

typedef struct node {
	char *lexeme;
	struct node *forward;
	struct node *previous;
};

typedef struct syntax_tree {
	int nullable;
	int *firstpos;
	int *lastpos;
	int *followpos;
	int position;
	char *regex;

	struct syntax_tree *left_child;
	struct syntax_tree *right_child;
};

void pos_test();

int get_input(const char *fp);

int match_language(char *);

void match_include(char *);

void get_firstpos(struct syntax_tree *, char *operation);

void get_nullable(struct syntax_tree *, char *operation);

void get_lastpos(struct syntax_tree *, char *operation);

void get_followpos(struct syntax_tree *, char *operation);

void create_dfa();

void test();

void writelines(char *arr[], int l);

void filecopy(char *ifp);

void add_lexeme(char *letter);

char *augment_re(char *);

struct lexemes *create_new(char *);

struct syntax_tree *create(char *, int);

#endif