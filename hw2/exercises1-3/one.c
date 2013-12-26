#include <stdio.h>

int main(void) {

	int while_counter = 1;
	while (while_counter <= 100) {
		printf("%d\n", while_counter);
		++while_counter;
	}

	int for_counter;
	for (for_counter = 1; for_counter <= 100; ++for_counter) {
		printf("%d\n", for_counter);
	}
	// for loop seems nicer
	return 0;
}