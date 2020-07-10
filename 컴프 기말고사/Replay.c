#define _CRT_SECURE_NO_WARNINGS
#include "Replay.h"
#include "Public_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

replaydata* createreplay(int x, int y) {
	replaydata* temp = (replaydata*)malloc(sizeof(replaydata));
	temp->location.x = x;
	temp->location.y = y;

	return temp;
}

void append(player* p, replaydata* newnode) {
	if (p->data == NULL) {
		newnode->link = newnode;
		p->data = newnode;
		return;
	}

	newnode->link = p->data->link;
	p->data->link = newnode;
	p->data = newnode;
}

char* getname() {
	static char fname[100];

	int count = 1;
	char charcount[3];

	while (1) { //replay(n).dat 생성
		char buffer[100] = "replay(";
		sprintf(charcount, "%d", count);
		strcat(buffer, charcount);
		strcat(buffer, ").dat");

		if (fopen(buffer, "r") == NULL) {	//파일이 존재하지 않다면 해당 이름으로 저장
			strcpy(fname, buffer);
			break;
		}

		count++;
	}

	return fname;
}

FILE* made_replay() {
	return fopen(getname(), "wb");
}

void savefile(player* p, int seed) {
	FILE* fp = made_replay();

	fwrite(&seed, sizeof(int), 1, fp); //시드값 저장
	replaydata* movement = p->data->link; //리플레이 시작부분

	do {
		replaydata* nextmovement = movement->link;

		if (movement->location.x != nextmovement->location.x && movement->location.y != nextmovement->location.y) {
			if (movement->link != p->data->link) {
				//오류 수정코드
				replaydata* next2movement = nextmovement->link;
				replaydata* correctionnode = (replaydata*)malloc(sizeof(replaydata));

				if (nextmovement->location.y == next2movement->location.y) {
					correctionnode->location.x = nextmovement->location.x;
					correctionnode->location.y = movement->location.y;
				}

				else if (nextmovement->location.x == next2movement->location.x) {
					correctionnode->location.x = movement->location.x;
					correctionnode->location.y = nextmovement->location.y;
				}

				correctionnode->link = nextmovement;
				movement->link = correctionnode;
			}
		}

		fwrite(movement, sizeof(replaydata), 1, fp);

		movement = movement->link;
	} while (movement != p->data->link);

	printf("저장이 완료되었습니다.\n");
	fclose(fp);
}
/*
int replaylist() {
	int count = 1;
	char charcount[3];

	while (1) { //replay(n).dat 생성
		char buffer[100] = "replay(";
		sprintf(charcount, "%d", count);
		strcat(buffer, charcount);
		strcat(buffer, ").dat");

		if (fopen(buffer, "r") != NULL) {	//파일이 존재한다면
			count++;
		}
		else {
			break;
		}
	}

	return count - 1;
}

FILE* getreplayfile() {
	int replaycount = replaylist();
	
	if (replaycount == 0) {
		printf("파일이 존재하지 않습니다.\n");
		exit(1);
	}

	int select = 0;
	int key;

	do {
		gotoxy(0, boardy + 2);
		for (int i = 1; i <= replaycount; i++) {
			if (select == i - 1)
				printf("▶▶");

			gotoxy(4, boardy + 1 + i);
			printf("    replay(%d).dat\n", i);
		}

		key = getch();
		if (key != 224)
			continue;

		key = getch();
		switch (key) {
		case direction_up:
			gotoxy(0, boardy + 2 + select);
			printf("    ");
			select = (select + replaycount - 1 ) % replaycount;
			break;
		case direction_down:
			gotoxy(0, boardy + 2 + select);
			printf("    ");
			select = (select + replaycount + 1) % replaycount;
			break;
		}
	} while (key != 13); //엔터 입력시 종료

	gotoxy(0, boardy + 2);
	for (int i = 1; i <= replaycount; i++) {
		printf("                                           \n");
	}
	
	char buffer[100] = "replay(";
	char charcount[3];
	sprintf(charcount, "%d", select + 1);
	strcat(buffer, charcount);
	strcat(buffer, ").dat");

	return fopen(buffer, "rb");
}
*/