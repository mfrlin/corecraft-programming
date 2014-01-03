#include <stdio.h>

int main(void) {
	const int LIMIT = 1000;
	int a, b, c;
	for (c = LIMIT; c > 0; c--) {
		for (b = LIMIT - c - 1, a = 1; b > a; b--, a++) {
			if (a*a + b*b == c*c) {
				printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
				return 0;
			}
		}
	}

	return 0;
}
