#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i = 0;
	char str[4];

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';

	printf("%s", str);
	/*
	while (str[i] != '\0') {
		printf("%c", str[i]);
		i++;
	}
	*/

	return 0;
}