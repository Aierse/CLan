#include <stdio.h>


int main(void) {
	char src[] = "The worst things is to eat for before you sleep";
	char dst[100];

	printf("원본 문자열 = %s\n", src);

	int i;
	for (i = 0; src[i] != '\0'; i++) {
		dst[i] = src[i];
	}

	dst[i] = '\0';

	printf("복사된 문자열 = %s\n", dst);

	return 0;
}