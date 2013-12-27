#include <stdio.h>
#define VARIABLES 6

int main(void) {

	int vowels[VARIABLES];
	int i;
	for (i = 0; i < VARIABLES; ++i) {
		vowels[i] = 0;
	}
	int c;
	while ((c = getchar()) != EOF) {
		if (c == 'a') {
			vowels[0] += 1;
			vowels[5] += 1;
		}
		if (c == 'e') {
			vowels[1] += 1;
			vowels[5] += 1;
		}
		if (c == 'i') {
			vowels[2] += 1;
			vowels[5] += 1;
		}
		if (c == 'o') {
			vowels[3] += 1;
			vowels[5] += 1;
		}
		if (c == 'u') {
			vowels[4] += 1;
			vowels[5] += 1;
		}
	}
	printf("Number of a's: %d\n", vowels[0]);
	printf("Number of e's: %d\n", vowels[1]);
	printf("Number of i's: %d\n", vowels[2]);
	printf("Number of o's: %d\n", vowels[3]);
	printf("Number of u's: %d\n", vowels[4]);
	printf("Number of vowels: %d\n", vowels[5]);

	return 0;
}