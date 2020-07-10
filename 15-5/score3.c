#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp = NULL;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	printf("새로 생성할 성적 파일 이름을 입력하세요 : ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "w")) == NULL) {
		fprintf(stderr, "성적 파일을 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (1) {
		printf("학번, 이름, 성적을 입력하세요 : (학번이 음수이면 종료) ");
		scanf("%d", &number);

		if (number < 0)	break;

		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);
	}

	fclose(fp);

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "성적 파일을 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %s %f", &number, name, &score);
		printf("name : %s\n", name);
		total += score;
		count++;
	}

	printf("평균 = %f\n", total / count);

	fclose(fp);
	return 0;
}