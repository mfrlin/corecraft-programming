#include <stdio.h>

void print_binary(int x);
int bitcount(unsigned x);

int main(void) {
	int n = 127;
	printf("%d\n", bitcount(n));

	return 0;
}

int bitcount(unsigned x) {
	int b;
	/* loop in this version is shorter
	 * previous version checks all the bits from right to the leftmost bit which is set to 1
	 * this version deletes rightmost 1 bit, so it loops only the amount of times it needs to delete all the 1 bits
	 */
	for (b = 0; x != 0; x &= x-1) {
		printf("%d\n", b);
		print_binary(x);
		print_binary(x-1);
		print_binary(x & x-1);
		b++;
	}
	return b;
}

void print_binary(int x) {
	int i;
	for (i = 0; i < sizeof(int) * 8; i++) {
		if (x < 0)
			putchar('1');
		else
			putchar('0');
		x = x << 1;	
	}
	putchar('\n');
}

