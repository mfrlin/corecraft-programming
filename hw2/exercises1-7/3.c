#include <stdio.h>

#define DIV_BY_ZERO -1

int div(int x, int y);

int main(void) {
	printf("10/5 = %d\n", div(10, 5));
	printf("Testing division by zero: %d\n", div(5, 0));

	return 0;
}

int div(int x, int y) {
	if (y == 0) {
		printf("%s\n", "Division by 0!");
		return DIV_BY_ZERO;
	}
	return x / y;
}