#include "User.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0

void initialize(player* p) {
	p->length = 0;
	p->speed = 280;
	p->movable = TRUE;
	p->direction = direction_right;
	p->olddirection = p->direction;
	p->last = NULL;
	p->data = NULL;

	insert_first(p, createnode(17, 6));
	insert_first(p, createnode(18, 6));
	insert_first(p, createnode(19, 6)); //머리
}

void gameovercheck(player* p, int x, int y) {
	ListNode* head = p->last->right;

	if (x < 0 || y < 0 || x >= boardx || y >= boardy)
		p->movable = FALSE;

	do {
		head = head->right;
		if (x == head->location.x && y == head->location.y)
			p->movable = FALSE;
	} while (head != p->last->right);
}

void printsnake(player* p) {
	static int firstcall = 1;
	ListNode* head = p->last->right;
	gotonode(head->location);
	printf("◆");

	if (firstcall) {
		do {
			head = head->right;
			gotonode(head->location);
			printf("■");
		} while (head != p->last);

		firstcall = 0;
	}
	else {
		head = head->right;
		gotonode(head->location);
		printf("■");
	}
}

void movehead(player* p, int movementx, int movementy) {
	ListNode* head = p->last->right;

	p->last->location = head->location;
	p->last->location.x += movementx;
	p->last->location.y += movementy;

	p->last = p->last->left; // last포인터를 마지막 노드 이전으로 설정
}

int getfeed(player* p, int x, int y) {
	Location head = { x, y };
	if (head.x == feed.x && head.y == feed.y) {
		insert_first(p, createnode(x, y));
		feed = setfeed(p);

		if (p->speed > 70)
			p->speed -= 70;

		return TRUE;
	}

	return FALSE;
}

void deletetail(player* p) { //화면상에서 표시된 꼬리의 위치를 지움
	Location tail = p->last->location;

	gotonode(tail);
	printf("  ");
}


void moving(player* p) {
	ListNode* head = p->last->right;
	int headx = head->location.x;
	int heady = head->location.y;

	int nowdirection = p->direction;
	int nowolddirection = p->olddirection;

	if (nowdirection != nowolddirection) { //방향이 바뀔때 기록
		append(p, createreplay(headx, heady));
	}

	switch (nowdirection) {
	case direction_left:
		gameovercheck(p, headx - 1, heady);
		if (getfeed(p, headx - 1, heady))
			return;
		deletetail(p);
		movehead(p, -1, 0);
		p->olddirection = direction_left;
		break;
	case direction_right:
		gameovercheck(p, headx + 1, heady);
		if (getfeed(p, headx + 1, heady))
			return;
		deletetail(p);
		movehead(p, 1, 0);
		p->olddirection = direction_right;
		break;
	case direction_down:
		gameovercheck(p, headx, heady + 1);
		if (getfeed(p, headx, heady + 1))
			return;
		deletetail(p);
		movehead(p, 0, 1);
		p->olddirection = direction_down;
		break;
	case direction_up:
		gameovercheck(p, headx, heady - 1);
		if (getfeed(p, headx, heady - 1))
			return;
		deletetail(p);
		movehead(p, 0, -1);
		p->olddirection = direction_up;
		break;
	}

	if (!p->movable) //게임 오버시 기록
		append(p, createreplay(head->location.x, head->location.y));
}