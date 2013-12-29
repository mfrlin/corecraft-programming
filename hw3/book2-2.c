#include <stdio.h>

int main(void) {
	int lim = 5;
	char s[lim];
	int c;
	int i;
	for (i = 0; i < lim-1; ++i) {
		if (!((c = getchar()) != '\n')) {
			break;
			if (!(c != EOF)) {
				break;
			}
		}
		s[i] = c;
	}
	s[i] = '\0';

	printf("%s\n", s);

	return 0;
}