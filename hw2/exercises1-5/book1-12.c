#include <stdio.h>
#define IN 1
#define OUT 0

int main(void) {

	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			/* state is used to clear excess whitespaces and tabs between words */
			if (state) {
				state = OUT;
				printf("\n");
			}
		}
		else {
			state = IN;
			printf("%c", c);
		}
	}

	return 0;
}