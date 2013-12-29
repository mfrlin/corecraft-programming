#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len);
int str_length(char s[]);
void reverse_inplace(char s[]);



int main(void) {
	int len;
	char line[MAXLINE];
	char reversed[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 1) {
		reverse(reversed, line, len);
		printf("%s\n", reversed);
	}
	
	return 0;
}

int getline(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c = '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char to[], char from[], int len) {
	int i;
	i = 0;
	len -= 1;
	while (i <= len) {
		to[len - i] = from[i];
		++i;
	}
	to[len+1] = '\0';
}

int str_length(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

void reverse_inplace(char s[]) {
    int i, len;

    /* figure out the length of the string */
    len = str_length(s);

    /* go from s[0] to s[len-1] until the middle is reached */
    for (i = 0, len = len - 1; i < len; ++i, --len)
    {
        /* swap s[i] and s[len] */
        char tmp = s[len];
        s[len] = s[i];
        s[i] = tmp;
    }
}