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

	printf("기회는 총 20번입니다.\n");

	while (TRUE) { //문자열이 일치하면 종료
		if (count == 20) {
			printf("실패하셨습니다.\n");
			break;
		}

		if (!strcmp(answer, problem)) {
			printf("성공하셨습니다!\n");
			break;
		}
		printf("문자열을 입력하시오: %s \n", answer);
		printf("글자를 추측하시오 : ");
		char ch = getchar();
		getchar(); //버퍼 비우기

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
	printf("제작자 : 20174434 조윤혁");
}