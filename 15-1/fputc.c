#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp = NULL;
	fp = fopen("sample.txt", "a");

	if (fp == NULL)
		printf("���Ͽ��� ����\n");
	else
		printf("���Ͽ��� ����\n");

	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);

	fclose(fp);
	return 0;
}