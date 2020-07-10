#include <stdio.h>

void swap(int x, int y) {
	x += 50;
	y += 50;

	int tmp = x;
	x = y;
	y = tmp;

	printf("x = %d y = %d\n", x, y);
}


void swap2(int* px, int* py) {
	*px += 50;
	*py += 50;
	
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int main(void) {
	int a = 100, b = 200;

	printf("a = %d, b= %d\n", a, b);

	swap(a, b);
	printf("a = %d, b= %d\n", a, b);

	swap2(&a, &b);
	printf("a = %d, b= %d\n", a, b);

	return 0;
}