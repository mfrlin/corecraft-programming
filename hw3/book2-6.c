#include <stdio.h>
#include <limits.h>

void print_binary(int x);
int setbits(int x, int p, int n, int y);

int main(void) {
	
	printf("%d\n", setbits(127, 5, 2, 10));

	return 0;
}

int setbits(int x, int p, int n, int y) {
	int mask = ~0; /* set mask to all 1s */
	printf("%s\n", "Creating mask:");
	print_binary(mask);
	/* mask should be in format: 11111...11100011 where p is 5 and n is 2 */
	mask = mask << p;
	print_binary(mask);
	mask = mask | ~(~0 << n);
	print_binary(mask);
	/* could have written mask = ~0 << p | ~(~0 << n); */
	printf("%s\n", "Original x: ");
	print_binary(x);
	x &= mask;
	printf("%s\n", "Masked x: ");
	print_binary(x);
	printf("%s\n", "Original y: ");
	print_binary(y);
	y &= ~mask;
	printf("%s\n", "Masked y: ");
	print_binary(y);
	x |= y;
	printf("%s\n", "Changed x: ");
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

