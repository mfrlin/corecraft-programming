#include <stdio.h>

void increment(int x);

int main(void) {
	/* name x also displays scoping */
	int x = 100;
	int n = 0;
	increment(n);
	increment(x);
	printf("%d\n", n);
	printf("%d\n", x);

	return 0;
}

void increment(int x) {
	x += 1;
} 