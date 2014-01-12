#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main(void) {
	char *s1 = "testone";
	char *s2 = "testtwo";
	char *t1 = "one";
	char *t2 = "testtwo";
	printf("%d\n", strend(s1, t1));
	printf("%d\n", strend(s2, t1));
	printf("%d\n", strend(s2, t2));
	printf("%d\n", strend(t1, t2));		

	return 0;
}

int strend(char *s, char *t) {
	int diff = strlen(s) - strlen(t);
	
	if (diff >= 0) {
		while (*(s + diff++) == *t++)
			if (*t == '\0')
				return 1;
	}
	return 0;
}