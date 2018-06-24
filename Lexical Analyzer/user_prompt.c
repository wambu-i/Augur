/* Augur - User Prompt.*/

#include <stdio.h>
#include "user_prompt.h"

#define BUFFER_SIZE 2048


int main(void) {
	user_prompt();
	return 0;
}

char user_prompt(void) {
	char prompt[BUFFER_SIZE];

	puts("Augur Version 0.0.1.");
	puts("Use CTRL + C to exit.\n");
	
	while (1) {
		fputs("Augur >> ", stdout);
		fgets(prompt, BUFFER_SIZE, stdin);
	}
}
