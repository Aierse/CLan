#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;

	char file1[100], file2[100];
	char buffer[100];

	printf("원본파일이름 : ");
	scanf("%s", file1);

	printf("복사파일이름 : ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "원본파일 %s을 열 수 없습니다.\n", file1);
		exit(1);
	}
	
	if ((fp2 =  fopen(file2, "w")) == NULL) {
		fprintf(stderr, "복사파일 %s을 열 수 없습니다.\n", file2);
		exit(1);
	}

	while (fgets(buffer, 100, fp1) != NULL) {
		printf("문장은 %s", buffer);
		fputs(buffer, fp2);
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}