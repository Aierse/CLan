#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
	char title[100];
	double rating;
} MOVIE;

int main(void) {
	MOVIE* movies;
	
	printf("�� ���̳� �����Ͻðڽ��ϱ�? ");
	int size;
	scanf("%d", &size);
	getchar();

	movies = (MOVIE*)malloc(sizeof(MOVIE) * size);
	if (movies == NULL) {
		printf("�����޸� �Ҵ� ����");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		printf("��ȭ ���� : ");
		gets_s(movies[i].title, 100);
		printf("��ȭ ���� : ");
		scanf("%lf", &movies[i].rating);
		getchar();
	}

	printf("===========================\n");
	printf("���� ����\n");
	printf("===========================\n");
	for (int i = 0; i < size; i++) {
		printf("%s \t %f\n", movies[i].title, movies[i].rating);
	}
	printf("===========================\n");
	
	free(movies);
	return 0;
}