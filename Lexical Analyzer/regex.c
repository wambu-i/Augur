#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>
#include <regex.h>
#include "analyzer.h"

#define DELIMITER "\\s"
#define IDENTIFIER "[A-Za-z][0-9A-Za-z]*(_[0-9A-Za-z]+)*( [A-Za-z][0-9A-Za-z]*(_[0-9A-Za-z]+)*:)"
#define INCLUDE "!verwenden (<[^>]+>)" 
#define BUFFER 2048


#define OVECCOUNT 120

static char *identifier = "[A-Za-z][0-9A-Za-z]*(_[0-9A-Za-z]+)*";
static char *header = "!verwenden (<[^>]+>)";
static char *function = "[A-Za-z]*(_[0-9A-Za-z]+)*\\([A-Za-z]*[0-9A-Za-z]*(_[0-9A-Za-z]+)*\\){1}";
static char *literal = "( ?:\'|\").*(?:\'|\")*";


static char language[BUFFER];

void create_regex() {
    strcpy(language, identifier);
    strcat(language, header);
    strcat(language, function);
    strcat(language, literal);
}


int match_language(char *line) {
    pcre *regex;
    const char *error;
    int error_offset, subject_length;
    int match;
    int ovector[OVECCOUNT];

    subject_length = (int) strlen(line);

    regex = pcre_compile(
        identifier,
        0,
        &error,
        &error_offset,
        NULL
    );

    if (regex == NULL) {
        fprintf(stderr, "%s\n", error);
        return EXIT_FAILURE;
    }

    match = pcre_exec(
        regex,
        NULL,
        line,
        subject_length,
        0,
        0,
        ovector,
        OVECCOUNT
    );

    if (match < 0) {
        switch(match) {
            case PCRE_ERROR_NOMATCH:
                printf("No match\n");
                break;
            default:
                printf("Matching error %d.\n", match);
                break;
        }
        pcre_free(regex);

        return EXIT_FAILURE;
    }

    printf("\nMatch succeeded at offset %d.\n", ovector[0]);
    printf("%d\n", match);

    for (int i = 0; i < match; i++) {
        char *start = line + ovector[2 * i];
        int substring_length = ovector[2 * i + 1] - ovector[2 * i];
        printf("%2d: %.*s\n", i, substring_length, start);
    }
    return 0;
}