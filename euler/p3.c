#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main() {

	int64_t x = 600851475143;
//	signed long long y = x -1;
	int64_t y;
	printf("%lld\n", x);

	for(y = 2; y < x; y++) {
		if(x % y == 0) {
			printf("%lld\n", y);
			break;
		}
	}

	printf("%lld \n", x / y);

	return 0;
}
