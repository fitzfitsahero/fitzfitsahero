#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	int i, x;

	for(i = 3; i < 1000; i++) {
		if(i % 3 == 0 || i % 5 == 0)
			x += i;
	}
	printf("%d\n", x);

	return 0;
}
