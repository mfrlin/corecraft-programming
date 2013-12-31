#include <stdio.h>

void copy(char s[], char d[], int size);

int main(void) {
	char source_short[] = "Today is a fine day.";
	char source_long[] = "Yesterday was a fine day too.";
	char destination[27];
	printf("source_short has space for %d characters.\n", sizeof(source_short)/sizeof(source_short[0]));
	copy(source_short, destination, sizeof(destination)/sizeof(destination[0]));
	printf("%s\n", destination);
	copy(source_long, destination, sizeof(destination)/sizeof(destination[0]));
	printf("%s\n", destination);
	return 0;
}

void copy(char s[], char d[], int size) {
	/* We see that this is wrong because d is treated as a char * pointer and not an array.
	 * This is called pointer decay. */
	printf("%d\n", sizeof(d));
	int i;
	for (i = 0; (d[i] = s[i]) != '\0'; i++) {
		if (i == size - 1) {
			d[i] = '\0';
			break;
		}
	}	
}