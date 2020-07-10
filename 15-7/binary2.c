#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void) {
	FILE* fp = NULL;
	int buffer[SIZE];

	fp = fopen("binary.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "파일 binary.bin을 열 수 없습니다.\n");
		exit(1);
	}

	fread(buffer, sizeof(int), SIZE, fp);

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", buffer[i]);
	}

	fclose(fp);
	return 0;
}2