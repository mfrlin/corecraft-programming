#include <stdio.h>

int main(void) {

	int c, ns, nl, nt;
	ns = nl = nt = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++ns;
		}
		if (c == '\n') {
			++nl;
		}
		if (c == '\t') {
			++nt;
		}
	}
	printf("Number of spaces: %d\n", ns);
	printf("Number of new lines: %d\n", nl);
	printf("Number of tabs: %d\n", nt);

	return 0;
}