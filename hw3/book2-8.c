#include <stdio.h>

void print_binary(int x);
int rightrot(int x, int n);

int main(void) {
	
	printf("%d\n", rightrot(170, 5));

	return 0;
}

int rightrot(int x, int n) {
	int mask = ~0 ^ ((unsigned)~0 >> 1);
	print_binary(mask);
	print_binary(x);
	for (n; n > 0; n--) {
		if (x & 1) {
			x >>= 1;
			x |= mask;
		}
		else {
			x >>= 1;
			x &= ~mask; /* we need to mask here because on some machines right shift is arithmetic */
			/* if x would be type unsigned we wouldn't have to mask because then right shift is logical */
		}
		print_binary(x);
	}
	return x;
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

