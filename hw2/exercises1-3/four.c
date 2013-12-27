# include <stdio.h>

int main(void) {

	/* predicted output is:
	 * i = 0, j = 0
	 * i = 0, j = 1
	 * i = 0, j = 2
	 * i = 0, j = 3
	 * i = 0, j = 4
	 * i = 0, j = 5
	 * i = 1, j = 0
	 * i = 1, j = 1
	 * ...
	*/

	int i, j;
	for (i = 0; i <= 5; i = i + 1) {
		// the inner loop runs 6 times with different i from outer loop
		for (j = 0; j <= 5; j = j + 1) {
			printf ("i = %d, j = %d\n", i, j);
		}
	}

	return 0;
}