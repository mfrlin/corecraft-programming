#include <stdio.h>

int main(void) {

	int c;
	while ((c = getchar()) != EOF) {
		if ('a' <= c && c <= 'z') {
			c -= 32;
		}
		
		printf("%c", c);
	}

	putchar('\n');

	return 0;
}