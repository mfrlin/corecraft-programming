#include <stdio.h>
#include <ctype.h>
#define NDRINKS 7

int main(void) {
	int drink_counter[NDRINKS];
	int i;
	for (i = 0; i < NDRINKS; i++) {
		drink_counter[i] = 0;
	}
	int c;
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			if (c - '0' > NDRINKS-1) {
				printf("%s %c\n", "Wrong input:", c);
			}
			else {
				drink_counter[c - '0'] += 1;
			}
		}

	}
	for (i = 0; i < NDRINKS; i++) {
		printf("Ordered %d of the drink number %d\n", drink_counter[i], i);
	}

	return 0;
} 