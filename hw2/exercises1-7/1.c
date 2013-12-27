#include <stdio.h>

int mul(int x, int y);

int main(void) {
	int i;
	for (i = 1; i <= 10; ++i) {
		printf("%d\n", mul(i, 5));
	}

	return 0;
}

int mul(int x, int y) {
	return x * y;
}