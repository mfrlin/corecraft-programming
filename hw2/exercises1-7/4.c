#include <stdio.h>

void number_print(int x, int y);

int main(void) {
	number_print(-10, 10);
	number_print(0, 1);
	number_print(1, 5);
	number_print(0, -10);
	number_print(0, 0);
	return 0;
}

void number_print(int x, int y) {
	int sum = 0;
	for (x += 1; x <= y; ++x) {
		printf("%d\n", x);
		sum += x;
	}
	printf("Accumulated value: %d\n", sum);
} 