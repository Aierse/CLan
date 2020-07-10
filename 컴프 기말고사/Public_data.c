#include "Public_data.h"
#include <windows.h>
Location feed;

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void gotonode(Location node) {
	gotoxy(node.x * 2 + 2, node.y + 1);
}

ListNode* createnode(int x, int y) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->location.x = x;
	temp->location.y = y;

	return temp;
}

void insert_first(player* p, ListNode* newnode) {
	p->length += 1;

	if (p->last == NULL) {
		p->last = newnode;
		newnode->left = newnode;
		newnode->right = newnode;
		return;
	}
	ListNode* head = p->last->right;

	head->left = newnode;
	p->last->right = newnode;

	newnode->right = head;
	newnode->left = p->last;
}