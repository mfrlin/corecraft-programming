#include <stdio.h>

int main(void) {

	int b;
	// it should print 1 for every character that is not EOF
	while (b = (getchar() != EOF)) {
		printf("%d", b);
	}
	putchar('\n');

	// should print 0 after exiting the loop
	printf("%d\n", b);

	return 0;
}