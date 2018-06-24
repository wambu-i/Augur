#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyzer.h"

#define MAXLINES 5000


char *read_lines[MAXLINES];
int elements;

void get_input(const char *fp) {
    FILE *contents;
    char *line = NULL;
    ssize_t read;
    size_t length;
    elements = 0;
    contents = fopen(fp, "r");
    if (contents == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &length, contents)) != -1) {
            line[strcspn(line,"\n")] = 0;
            read_lines[elements++] = line;
            line = NULL;
    }
    fclose(contents);
    free(line);
}

void writelines(char *arr[], int l) {
    int i;

    for (i = 0; i < l; i++) {
        printf("%s\n", arr[i]);
    }
}

void filecopy(char *ifp){
    printf("%s", ifp);
}