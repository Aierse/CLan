#include <stdio.h>

int main(void) {
	char* p = "Hello World";
	printf("%s\n", p);

	p = "Welcome to C World!";
	printf("%s\n", p);

	char q[] = "GoodBye";
	printf("%s\n", q);

	q[0] = 'a';
	printf("%s\n", q);

	return 0;
} 