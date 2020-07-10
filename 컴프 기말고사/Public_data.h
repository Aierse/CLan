#pragma once
#define boardx 37	//게임판 x크기
#define boardy 13	//게임판 y크기

typedef struct {
	int x;
	int y;
} Location;

typedef struct {	//이중 연결리스트
	struct ListNode* left;
	struct ListNode* right;
	Location location;
} ListNode; 

typedef struct {
	struct replaydata* link;
	Location location;
} replaydata;

typedef struct {	
	ListNode* last; //원형 연결리스트
	replaydata* data;
	int olddirection; //이전의 이동 방향
	int direction;	//이동 방향
	int length;		//몸통 길이
	int speed;		//이동 속도
	int movable;	//이동 가능한지 판단하는 bool값 ( 게임오버 판단 )
} player;

void insert_first(player* p, ListNode* newnode);

ListNode* createnode(int x, int y);

void gotoxy(int x, int y);

void gotonode(Location node);

extern Location feed; //먹이를 전역변수로 지정