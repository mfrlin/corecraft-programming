#include <stdio.h>

int main(void) {
	int i;
	/* int too small, float or double too large */
	unsigned sum = 0;
	for (i = 1; i < 100000; i++) {
		if (!(i % 3) || !(i % 5)) {
			sum += i;
		}
	}
	printf("%u\n", sum);

	return 0;
}
