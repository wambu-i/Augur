#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyzer.h"

#define MAXLINES 5000
#define BUFFER_SIZE 4096


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
        return EXIT_FAILURE;
    while ((read = getline(&line, &length, contents)) != -1) {
            line[strcspn(line,"\n")] = 0;
            read_lines[elements++] = line;
            line = NULL;
    }
    fclose(contents);
    free(line);
}

void create_buffer(const char *fp) {
    FILE *contents;
    unsigned long size;
    size_t number;
    size_t space;
    size_t read;
    char *buffer;
    contents = fopen(fp, "r");

    if (contents == NULL) {
        fprintf(stderr, "Unable to open source file.\n");
        return EXIT_FAILURE;
    }

    fseek(contents,0, SEEK_END);
    size = ftell(contents);
    fseek(contents, 0, SEEK_SET);

    number = (size % sizeof(int) ? 1 : 0) + (size / sizeof(int));
    space = (size % BUFFER_SIZE ? 1 : 0) + (size / BUFFER_SIZE);

    if (!(buffer = malloc(number * sizeof(int)))) {
        fprintf(stderr, "Could not allocate required memory.\n");
        return EXIT_FAILURE;
    }

    read = fread(buffer, BUFFER_SIZE, space, contents);
}

void filecopy(char *ifp){
    printf("%s", ifp);
}