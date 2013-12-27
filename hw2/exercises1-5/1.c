#include <stdio.h>

int main(void) {

	if (1 == 1) {
		printf("Always true.\n");
	}
	if (1 == 0) {
		printf("This should never print");
	} else {
		printf("Always false.\n");
	}

	return 0;
}