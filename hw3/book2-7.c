#include <stdio.h>

void print_binary(int x);
int invert(int x, int p, int n);

int main(void) {
	
	printf("%d\n", invert(170, 5, 2));

	return 0;
}

int invert(int x, int p, int n) {
	int mask = ~0 << p | ~(~0 << p-n);
	print_binary(x);
	print_binary(mask);
	int y = ~(x | mask);
	print_binary(y);
	x &= mask;
	print_binary(x);
	x |= y;
	print_binary(x);

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

