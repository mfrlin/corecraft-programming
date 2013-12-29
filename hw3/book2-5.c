#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(void) {
	char s1[] = "abcdefg";
	char s2[] = "xebc";
	int pos = any(s1, s2);
	printf("%d\n", pos);

	return 0;	
}

int any(char s1[], char s2[]) {
	int i, min, k;
	min = strlen(s1);
	char c;
	for (i = 0; s1[i] != '\0'; i++) {
		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k] && i < min) {
				min = i;
				break;
			}
		}
	}
	if (min == strlen(s1))
		return -1;
	else
		return min;
}