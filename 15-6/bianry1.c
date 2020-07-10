#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void) {
	FILE* fp = NULL;
	int buffer[SIZE] = { 10, 20, 30, 40, 50 };
	
	fp = fopen("binary.bin", "wb");
	if (fp == NULL) {
		fprintf(stderr, "���� binary.bin�� �� �� �����ϴ�.\n");
		exit(1);
	}

	fwrite(buffer, sizeof(int), SIZE, fp);

	fclose(fp);
	return 0;
}