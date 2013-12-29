#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	printf("Bits in char: %d\n", CHAR_BIT);

	printf("Max value of char: %d\n", CHAR_MAX);
	printf("Min value of char: %d\n", CHAR_MIN);
	printf("Max value of short %d\n", SHRT_MAX);
	printf("Min value of short: %d\n", SHRT_MIN);
	printf("Max value of int: %d\n", INT_MAX);
	printf("Min value of int: %d\n", INT_MIN);
	printf("Max value of long: %d\n", LONG_MAX);
	printf("Min value of long: %d\n", LONG_MIN);

	printf("Max value of unsigned char: %d\n", UCHAR_MAX);
	printf("Max value of unsigned short: %d\n", USHRT_MAX);
	printf("Max value of unsigned int: %u\n", UINT_MAX);
	printf("Max value of unsigned long: %lu\n", ULONG_MAX);

	printf("Max value of float: %e\n", FLT_MAX);
	printf("Min value of float: %e\n", FLT_MIN);

	printf("Max value of double: %e\n", DBL_MAX);
	printf("Min value of double: %e\n", DBL_MIN);

	printf("Max value of long double: %Le\n", LDBL_MAX);
	printf("Min value of long double: %Le\n", LDBL_MIN);

}