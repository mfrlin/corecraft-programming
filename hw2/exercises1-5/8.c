#include <stdio.h>

int main(void) {

	int c, vowel_count;
	vowel_count = 0;
	while ((c = getchar()) != EOF) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			++vowel_count;
		}
	}
	printf("Number of vowels: %d\n", vowel_count);

	return 0;
}