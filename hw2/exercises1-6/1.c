#include <stdio.h>
#define MAX_VOWELS 5

int main(void) {

	int vowels[MAX_VOWELS];
	int i;
	for (i = 0; i < MAX_VOWELS; ++i) {
		vowels[i] = 0;
	}
	int c;
	while ((c = getchar()) != EOF) {
		if (c == 'a') {
			vowels[0] += 1;
		}
		if (c == 'e') {
			vowels[1] += 1;
		}
		if (c == 'i') {
			vowels[2] += 1;
		}
		if (c == 'o') {
			vowels[3] += 1;
		}
		if (c == 'u') {
			vowels[4] += 1;
		}
	}
	printf("Number of a's: %d\n", vowels[0]);
	printf("Number of e's: %d\n", vowels[1]);
	printf("Number of i's: %d\n", vowels[2]);
	printf("Number of o's: %d\n", vowels[3]);
	printf("Number of u's: %d\n", vowels[4]);

	return 0;
}