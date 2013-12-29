#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {
	char s1[] = "abcdefg";
	char s2[] = "cd";
	squeeze(s1, s2);
	printf("%s\n", s1);

	return 0;	
}

void squeeze(char s1[], char s2[]) {
	int i, j, k;
	short found = 0;
	char c;
	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; (c = s2[k]) != '\0' && !found; k++) {
			if (s1[i] == c) {
				found = 1;
				break;
			}
		}
		if (!found) {
			s1[j++] = s1[i];
		}
		else { 
			found = 0;
		}
	}
	s1[j] = '\0';
}