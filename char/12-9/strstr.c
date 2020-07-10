#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char s[] = "A joy that's shared is a joy made double";
	char sub[] = "joy";

	char* p = strstr(s, sub);
	int loc = (int)(p - s);

	if (p != NULL)
		printf("첫번째 %s가 %d에서 발견되었음\n", sub, loc);
	else
		printf("%s가 발견되지 않았음\n", sub);


	return 0;
}