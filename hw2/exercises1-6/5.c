#include <stdio.h>
#define DIGITS 10

int main(void) {

	int ndigits[DIGITS];
	int i;
	for (i = 0; i < DIGITS; ++i) {
		ndigits[i] = 0;
	}
	int c;
	while ((c = getchar()) != EOF) {
		if ('0' <= c && c <= '9') {
			ndigits[c-'0'] += 1;
		}
	}
	
	for (i = 0; i < DIGITS; ++i) {
		printf("Found %d %ds\n", ndigits[i], i);
	}

	return 0;
}