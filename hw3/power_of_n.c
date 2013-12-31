#include <stdio.h>
typedef enum { false, true } bool;

double ipow(int base, int exp);

int main(void) {
	printf("%f\n", ipow(5, 6));
	printf("%f\n", ipow(5, -6));
	return 0;
} 
/* Exponentiation by squaring */
double ipow(int base, int exp) {
	bool negative = false;
	if (exp < 0) {
		negative = true;
		exp *= -1;
	}
    int result = 1;
    while (exp) {
        if (exp & 1) { /* tells us if exp is even or odd number by checking if LSB is 1 */
            result *= base; /* if it's odd we multiply the result with base */
        }
        /* no need to worry about arithmetic right shift because exp is always positive */
        exp >>= 1; /* exp/2 */
        base *= base; /* square the base */
        /* in our example 5^6 becomes: 5^2 * (5^2)^2
         * first loop: result = 1
         *             base = 5^2 = 25
         *             exp = 6/2 = 3
         * second loop: result = 1 * 25 = 25
         *              base = 25 ^ 2 = 625
         *              exp = 3/2 = 1
         * third loop: result = 25 * 625 = 15625
		 *             base = 625 ^ 2 = it doesn't matter because exp is 0
		 *             exp = 1/2 = 0 
         */
    }
    if(negative) {
		return (1.0/result);
	}
	return result;
}