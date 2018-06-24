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
