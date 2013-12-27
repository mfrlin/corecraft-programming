#include <stdio.h>
#define VARIABLES 3

int main(void) {

	int vowels[VARIABLES];
	int i;
	for (i = 0; i < VARIABLES; ++i) {
		vowels[i] = 0;
	}
	int c;
	while ((c = getchar()) != EOF) {
		// if else doesn't do anything in this exercise
		// and we can't use else because we have to check conditions for each case
		// so the solution uses only if statements
		if ('a' <= c && c <= 'z') {
			vowels[0] += 1;
		}
		if ('A' <= c && c <= 'Z') {
			vowels[1] += 1;
		}
		if ('0' <= c && c <= '9') {
			vowels[2] += 1;
		}
	}
	printf("Number of lowercase: %d\n", vowels[0]);
	printf("Number of uppercase: %d\n", vowels[1]);
	printf("Number of digits: %d\n", vowels[2]);

	return 0;
}