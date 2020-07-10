#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp = NULL;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	printf("���� ������ ���� ���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "w")) == NULL) {
		fprintf(stderr, "���� ������ �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	while (1) {
		printf("�й�, �̸�, ������ �Է��ϼ��� : (�й��� �����̸� ����) ");
		scanf("%d", &number);

		if (number < 0)	break;

		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);
	}

	fclose(fp);

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "���� ������ �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %s %f", &number, name, &score);
		printf("name : %s\n", name);
		total += score;
		count++;
	}

	printf("��� = %f\n", total / count);

	fclose(fp);
	return 0;
}