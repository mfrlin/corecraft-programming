#include <stdio.h>
#define PI 3.14

int main(void) {

	int r;
	for (r = 1; r <= 10; ++r) {
		printf("Area of the circle with radius %d is: %.2f\n", r, r*r*PI);
	}

	return 0;
}