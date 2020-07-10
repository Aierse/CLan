#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define playmode 10
#define replaymode 20

void CursorView(char show)//커서숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

DWORD WINAPI changedirection(player* p);

void title() {
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
	printf("■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
	printf("■□□■■■■■□□■□□□■□□□□■□□□□■□□□■□□■■■■■□□■\n");
	printf("■□□■□□□□□□■■□□■□□□■□■□□□■□□■□□□■□□□□□□■\n");
	printf("■□□■■■■■□□■□■□■□□■□□□■□□■■■□□□□■■■■■□□■\n");
	printf("■□□□□□□■□□■□□■■□□■■■■■□□■□□■□□□■□□□□□□■\n");
	printf("■□□■■■■■□□■□□□■□□■□□□■□□■□□□■□□■■■■■□□■\n");
	printf("■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
	printf("■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

int menu() {
	printf("■■■■■■■■■■■■■■■■■ 1.시작하기 ■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■ 2.리플레이 ■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■ 3.종료하기 ■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

	char select = NULL;

	while (!(select == '1' || select == '2' || select == '3')) {
		select = getch();
	}
	if (select == '1')
		return playmode;
	if (select == '2')
		return replaymode;
	if (select == '3')
		exit(1);

	return menu(); // 제대로 입력되지 않았으면 재귀호출
}

void printdisplay(player* p) {
	gotoxy(0, boardy + 1);

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■SPEED     ■■■■LENGTH    ■■■■SCORE         ■■■    ");
	if (p->direction == direction_up) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("    ■■■\n");
	}
	else {
		printf("■    ■■■\n");
	}
	printf("■■■          ■■■■          ■■■■              ■■■  ");
	if (p->direction == direction_left) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("  ");
	}
	else {
		printf("■  ");
	}

	if (p->direction == direction_right) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("  ■■■\n");
	}
	else {
		printf("■  ■■■\n");
	}

	printf("■■■       %3d■■■■       %3d■■■■         %5d■■■    ", p->speed, p->length, (p->length - 3) * 100, p->direction == direction_right ? "RIGHT" : p->direction == direction_left ? "LEFT" : p->direction == direction_up ? "UP" : "DOWN");
	if (p->direction == direction_down) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("    ■■■\n");
	}
	else {
		printf("■    ■■■\n");
	}

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void printboard(player* p) {
	gotoxy(0, 0);

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printf("■                                                                          ■\n");
	printdisplay(p);
}

DWORD WINAPI changedirection(player* p) {
	while (p->movable) {
		int key = getch();

		if (key != 224)
			continue;

		key = getch();
		switch (key) {
		case direction_left:
			if (p->olddirection != direction_right)
				p->direction = direction_left;
			break;
		case direction_right:
			if (p->olddirection != direction_left)
				p->direction = direction_right;
			break;
		case direction_up:
			if (p->olddirection != direction_down)
				p->direction = direction_up;
			break;
		case direction_down:
			if (p->olddirection != direction_up)
				p->direction = direction_down;
			break;
		}
	}

	return 0;
}

int main(void) {
	CursorView(0);
	title();

	int seed;
	player user;
	initialize(&user);

	if (menu() == playmode) {
		seed = time(NULL);
		srand(seed);
		feed = setfeed(&user);

		printboard(&user);
		printsnake(&user);
		printfeed(&feed);

		HANDLE hThrd; //스레드
		DWORD threadId;
		hThrd = CreateThread(NULL, 0, changedirection, (player*)&user, 0, &threadId);

		while (user.movable) {
			Sleep(user.speed);
			moving(&user);

			printdisplay(&user);
			printsnake(&user);
		}

		gotonode((Location) { 0, boardy + 4 });
		printf("\n");
		savefile(&user, seed);
	}
	else {
		printf("파일이름을 입력하세요 : ");
		char fname[100];
		scanf("%s", fname);
		
		FILE* fp = fopen(fname, "rb");

		if (fp == NULL) {
			printf("파일을 찾을 수 없습니다.\n");
			exit(1);
		}
		
		fread(&seed, sizeof(int), 1, fp);
		srand(seed);
		feed = setfeed(&user);

		printboard(&user);
		printsnake(&user);
		printfeed(&feed);


		while (!feof(fp)) { //파일이 끝날때까지 반복
			replaydata movement;
			fread(&movement, sizeof(replaydata), 1, fp);
			ListNode* head = user.last->right;

			if (head->location.x < movement.location.x && head->location.y == movement.location.y)
				user.direction = direction_right;
			else if (head->location.x > movement.location.x && head->location.y == movement.location.y)
				user.direction = direction_left;
			else if (head->location.x == movement.location.x && head->location.y < movement.location.y)
				user.direction = direction_down;
			else if (head->location.x == movement.location.x && head->location.y > movement.location.y)
				user.direction = direction_up;

			while (1) {
				head = user.last->right;

				if (head->location.x == movement.location.x && head->location.y == movement.location.y || !user.movable)
					break;

				Sleep(user.speed);
				moving(&user);

				printdisplay(&user);
				printsnake(&user);
			}
		}

		gotonode((Location) { 0, boardy + 4 });
		printf("\n");
	}

	system("pause");
	return 0;
}