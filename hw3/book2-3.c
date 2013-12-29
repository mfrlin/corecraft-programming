#include <stdio.h>
#include <string.h>


int htoi(char s[]);

int main(void) {
	char s[] = "0xFFFF";
	printf("%d\n", htoi(s));

	return 0;
}

int htoi(char s[]) {
	int result = 0;
	int i = 0;
	int value;
	/* check if it starts with 0x */
	if (strlen(s) > 1 && s[1] == 'x' || s[1] == 'X') {
		i = 2;
	}
	for (i; s[i] != '\0'; ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			value = s[i] - '0';
		}
		if ('a' <= s[i] && s[i] <= 'f') {
			value = 10 + s[i] - 'a';
		}
		if ('A' <= s[i] && s[i] <= 'F') {
			value = 10 + s[i] - 'A';
		}
		printf("%d\n", value);

		result = 16 * result + value;
	}

	return result;
} 