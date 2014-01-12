#include <stdio.h>

void mystrcat(char *, char *);

int main(void) {
	char s[10] = "test";
	char *t = "one";
	mystrcat(s, t);
	printf("%s\n", s);	

	return 0;
}

void mystrcat(char *s, char *t) {
	for ( ; *s; s++)
		;
	while (*s++ = *t++)
		;
}