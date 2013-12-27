#include <stdio.h>

float mul(float x, float y);

int main(void) {
	
	printf("%f\n", mul(2.5, 0.5));

	return 0;
}

float mul(float x, float y) {
	return x * y;
}