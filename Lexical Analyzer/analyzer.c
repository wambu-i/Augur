#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "analyzer.h"

char *ttt = "This is a test";

void test() {
    for (int i = 0; i < elements; i++){
        match_language(read_lines[i]);
    }
}

