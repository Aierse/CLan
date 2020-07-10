#include <stdio.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define WIDTH 3
#define HEIGHT 3
#define EMPTY ' '
#define PLAYERMARK1 'O'
#define PLAYERMARK2 'X'

int endcheck(char board[WIDTH][HEIGHT]) {
	//가로로 3개를 완성했는지 체크
	for (int x = 0; x < WIDTH; x++) {
		int playercount1 = 0;
		int playercount2 = 0;

		for (int y = 0; y < HEIGHT; y++) {
			if (board[x][y] == EMPTY)	break;
			if (board[x][y] == PLAYERMARK1)	playercount1++;
			if (board[x][y] == PLAYERMARK2)	playercount2++;

			if (playercount1 == 3)	return 1;
			if (playercount2 == 3)	return 2;
		}
	}

	//세로로 3개를 완성했는지 체크
	for (int y = 0; y < HEIGHT; y++) {
		int playercount1 = 0;
		int playercount2 = 0;

		for (int x = 0; x < WIDTH; x++) {
			if (board[x][y] == EMPTY)	break;
			if (board[x][y] == PLAYERMARK1)	playercount1++;
			if (board[x][y] == PLAYERMARK2)	playercount2++;

			if (playercount1 == 3)	return 1;
			if (playercount2 == 3)	return 2;
		}
	}

	int playercount1 = 0;
	int playercount2 = 0;

	//대각선 체크
	for (int i = 0; i < WIDTH; i++) {
		if (board[i][i] == EMPTY)	break;
		if (board[i][i] == PLAYERMARK1)	playercount1++;
		if (board[i][i] == PLAYERMARK2)	playercount2++;
	}

	if (playercount1 == 3)	return 1;
	if (playercount2 == 3)	return 2;

	playercount1 = 0;
	playercount2 = 0;

	if (board[0][2] == PLAYERMARK1 && board[1][1] == PLAYERMARK1 && board[2][0] == PLAYERMARK1)	return 1;
	if (board[0][2] == PLAYERMARK2 && board[1][1] == PLAYERMARK2 && board[2][0] == PLAYERMARK2)	return 2;

	return FALSE; // 아무일도 없다면 
}

void printboard(char board[WIDTH][HEIGHT]) {
	for (int i = 0; i < HEIGHT; i++) {
		printf("---|---|---\n");
		printf(" %c | %c | %c \t", board[i][0], board[i][1], board[i][2]);
		printf("%d,%d   %d,%d  %d,%d\n", i, 0, i, 1, i, 2);
	}
	printf("---|---|---\n");
}

void clearboard(char board[WIDTH][HEIGHT]) {
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			board[x][y] = EMPTY;
		}
	}
}

void seating(char board[WIDTH][HEIGHT], char playermark) {
	int x, y;

	if (playermark == PLAYERMARK1) { //플레이어 착석
		printf("(x, y) 좌표 : ");
		scanf("%d %d", &x, &y);

		if (board[x][y] != EMPTY) {
			printf("잘못 착석하셨습니다! 다시 착석하세요.\n");
			return seating(board, playermark);
		}
	}
	else { // AI 착석
		printf("AI 착석\n");
		do {
			x = rand() % WIDTH;
			y = rand() % HEIGHT;
		} while (board[x][y] != EMPTY);
	}

	board[x][y] = playermark;
}

int main(void) {
	srand(time(NULL));
	int winner = 0;
	char board[3][3];

	printf("게임시작!\n");
	clearboard(board);
	printboard(board);

	for (int i = 0; i < WIDTH * HEIGHT; i++) {
		seating(board, i % 2 == 0 ? PLAYERMARK1 : PLAYERMARK2);
		printboard(board);
		winner = endcheck(board);

		if (winner != 0) break;
	}

	printf("PLAYER%d 승!\n", winner);
	printf("제작자 : 20174434 조윤혁");
	return 0;
}