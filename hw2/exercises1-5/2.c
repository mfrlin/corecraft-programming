#include <stdio.h>

int main(void) {

	int c;
	while ((c = getchar()) != EOF) {
		printf("%c", c);
	}

	putchar('\n');

	return 0;
}