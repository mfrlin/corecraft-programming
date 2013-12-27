#include <stdio.h>

int main(void) {

	int m = 4;
	int n;
	for (n = 1; n <= 10; ++n) {
		printf("%d\n", n * m);
	}
	
	return 0;
}