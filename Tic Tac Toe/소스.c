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
	//���η� 3���� �ϼ��ߴ��� üũ
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

	//���η� 3���� �ϼ��ߴ��� üũ
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

	//�밢�� üũ
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

	return FALSE; // �ƹ��ϵ� ���ٸ� 
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

	if (playermark == PLAYERMARK1) { //�÷��̾� ����
		printf("(x, y) ��ǥ : ");
		scanf("%d %d", &x, &y);

		if (board[x][y] != EMPTY) {
			printf("�߸� �����ϼ̽��ϴ�! �ٽ� �����ϼ���.\n");
			return seating(board, playermark);
		}
	}
	else { // AI ����
		printf("AI ����\n");
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

	printf("���ӽ���!\n");
	clearboard(board);
	printboard(board);

	for (int i = 0; i < WIDTH * HEIGHT; i++) {
		seating(board, i % 2 == 0 ? PLAYERMARK1 : PLAYERMARK2);
		printboard(board);
		winner = endcheck(board);

		if (winner != 0) break;
	}

	printf("PLAYER%d ��!\n", winner);
	printf("������ : 20174434 ������");
	return 0;
}