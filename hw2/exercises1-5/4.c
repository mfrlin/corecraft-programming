#include <stdio.h>

int main(void) {

	int c, ns, nl;
	ns = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++ns;
		}
		if (c == '\n') {
			++nl;
		}
	}
	printf("Number of spaces: %d\n", ns);
	printf("Number of new lines: %d\n", nl);

	return 0;
}