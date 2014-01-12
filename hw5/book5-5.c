#include <stdio.h>

void mystrcat(char *, char *, int);
int mystrcmp(char *, char *, int);
void mystrcpy(char *, char *, int);

int main(void) {
	char s[10] = "test";
	char *t = "one";
	mystrcat(s, t, 2);
	printf("%s\n", s);	

	char *s1 = "testone";
	char *s2 = "testtwo";
	printf("%d\n", mystrcmp(s1, s2, 3));
	printf("%d\n", mystrcmp(s1, s2, 4));
	printf("%d\n", mystrcmp(s1, s2, 123));

	char s3[10];
	mystrcpy(s3, s1, 100);
	printf("%s\n", s3);
	mystrcpy(s3, s1, 3);
	printf("%s\n", s3);
	mystrcpy(s3, s1, 5);
	printf("%s\n", s3);

	return 0;
}

void mystrcat(char *s, char *t, int n) {
	for ( ; *s; s++)
		;
	int i = 0;
	while (i++ < n && (*s++ = *t++))
		;
	*s = '\0';
}

int mystrcmp(char *s, char *t, int n) {
	for ( ; *s == *t && n > 1; s++, t++, n--)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

void mystrcpy(char *s, char *t, int n) {
	while (n-- && (*s++ = *t++))
		;
	*s = '\0';
}