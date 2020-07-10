#include <stdio.h>

void sub(int* b, int n) {
	*b = 4;
	b++;
	*b = 5;
	b++;
	*b = 6;
}

int main(void) {
	int a[3] = { 1,2,3 };

	printf("%d %d %d\n", a[0], a[1], a[2]);
	sub(a, 3);
	printf("%d %d %d\n", a[0], a[1], a[2]);

	return 0;
}