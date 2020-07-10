#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define WORDS 5
#define TRUE 1
#define FALSE 0
void initializing(char answer[], char problem[]) {
	char temp[100] = {' '};

	for (int i = 0; i < strlen(problem); i++) {
		if (isalpha(problem[i]))
			temp[i] = '_';
		else
			temp[i] = ' ';
	}

	strcpy(answer, temp);
}

int main(void) {
	srand(time(NULL));

	char solution[WORDS][100] = {
		{"meet at midnight"},
		{"Hello World"},
		{"Gwanju University"},
		{"C Language Express"},
		{"Made By JoYunHyuk"}
	};
	char problem[100];
	strcpy(problem, solution[rand() % WORDS]);

	char answer[100];
	initializing(answer, problem);

	int count = 0;

	printf("��ȸ�� �� 20���Դϴ�.\n");

	while (TRUE) { //���ڿ��� ��ġ�ϸ� ����
		if (count == 20) {
			printf("�����ϼ̽��ϴ�.\n");
			break;
		}

		if (!strcmp(answer, problem)) {
			printf("�����ϼ̽��ϴ�!\n");
			break;
		}
		printf("���ڿ��� �Է��Ͻÿ�: %s \n", answer);
		printf("���ڸ� �����Ͻÿ� : ");
		char ch = getchar();
		getchar(); //���� ����

		for (int i = 0; i < strlen(problem); i++) {
			if (problem[i] == ch)
				answer[i] = ch;
			if (problem[i] == toupper(ch))
				answer[i] = toupper(ch);
			if (problem[i] == tolower(ch))
				answer[i] = tolower(ch);
		}
		count++;
	}
	printf("������ : 20174434 ������");
}