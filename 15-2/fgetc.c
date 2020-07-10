#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp = NULL;
	int c;
	fp = fopen("sample.txt", "r");

	if (fp == NULL)
		printf("파일열기 실패\n");
	else
		printf("파일열기 성공\n");

	while ((c = fgetc(fp)) != EOF)
		putchar(c);


	fclose(fp);
	return 0;
}