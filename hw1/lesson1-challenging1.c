#include <stdio.h>

int main() {
	int divisor = 10; // divisible by
	int i = 1; // start
	int end = 100; // end
	int counter = 1;
	// because inner while loop doesn't stop when condition of the outer loop is false
	// we must take that into account in outer condition
	// if we end at 100 and divisor is 6 we get 96 as the last number
	// but because 96 < 100 we enter the inner loop and we count to 102
	// this is why we subtract divisor from end and add 1
	// we add another 1 because we have < operator
	// if we had =< we wouldnt need to subtract additional 1
	while (i < end-divisor+1+1) {
		while (i/divisor < counter) {
			i++;
		}
		printf("%d\n", i);
		counter++;
		i++;
	}
	return 0;
}