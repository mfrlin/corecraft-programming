#include <stdio.h>

int main(void) {

	int c, ns;
	ns = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++ns;
		}
	}
	printf("Number of spaces: %d\n", ns);

	return 0;
}