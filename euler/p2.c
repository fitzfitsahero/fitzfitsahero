#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

	int i, x, y, z;
	x = 0;
	y = 1;

	while(x < 4000000 || y < 4000000) {
	//	printf("x: %d  y: %d\n", x, y);
		z = x + y;
		x = y;
		y = z;
		if(z % 2 == 0)
			i += z;
	}
	printf("%d\n", i);

	return 0;
}
