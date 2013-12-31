#include <stdio.h>
typedef enum { false, true } bool;

void caesar(char m[], int key, bool decrypt);

int main(void) {
	char message[] = "TODAY IS A FINE DAY ZZZ.";
	caesar(message, 3, false);
	printf("%s\n", message);
	caesar(message, 3, true);
	printf("%s\n", message);

	return 0;
}

void caesar(char m[], int key, bool decrypt) {
	if (decrypt) {
		key *= -1;
	}
	/* we assume we get as input only upper case alphabetical characters A-Z and we leave all the rest as they are. */
	int range = 'Z' - 'A' + 1;
	int temp;
	int i;
	for (i = 0; m[i] != '\0'; i++) {
		if ('A' <= m[i] && m[i] <= 'Z') {
			temp = (m[i] - 'A' + key) % range;
			m[i] = (temp >= 0) ? temp + 'A' : temp + 'Z' + 1; 
		}
	}
}