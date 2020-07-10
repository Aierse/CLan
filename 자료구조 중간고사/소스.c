#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* create_node(element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	return p;
}

typedef struct CListType {
	ListNode* last;
} CListType;

void init(CListType* list) {
	list->last = NULL;
}

void insert_first(CListType* head, ListNode* node) {
	if (head->last == NULL) {
		head->last = node;
		node->link = node;
	}
	else {
		node->link = head->last->link;
		head->last->link = node;
	}
}

void insert_last(CListType* head, ListNode* node) {
	if (head->last == NULL) {
		head->last = node;
		node->link = node;
	}
	else {
		node->link = head->last->link;
		head->last->link = node;
		head->last = node;
	}
}

void display(CListType* list) {
	if (list == NULL) {
		fprintf(stderr, "오류!");
		exit(1);
	}

	ListNode* head = list->last->link; // 첫부분
	ListNode* p = head; // 처음으로 이동

	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head);

	printf("\n");
}

ListNode* search(CListType* list, element data) {
	if (list == NULL) {
		fprintf(stderr, "오류!");
		exit(1);
	}

	ListNode* head = list->last->link;
	ListNode* p = head;

	do {
		if (p->data == data)
			return p;

		p = p->link;
	} while (p != head);

	return NULL; // 탐색결과가 없으면 NULL 반환
}

int get_size(CListType* list) {
	if (list == NULL)
		return 0;

	ListNode* head = list->last->link; // 첫부분
	ListNode* p = head;
	
	int count = 0; // 마지막 노드는 누락되므로 1부터 시작

	do {
		count++;
		p = p->link;
	} while (p != head);

	return count;
}

int main(void) {
	CListType list;

	init(&list);

	insert_first(&list, create_node(5));
	insert_first(&list, create_node(4));
	insert_first(&list, create_node(3));
	insert_first(&list, create_node(2));
	insert_first(&list, create_node(1));
	insert_last(&list, create_node(10));

	display(&list);
	printf("리스트 크기 : %d\n", get_size(&list));

	ListNode* searchdata = search(&list, 3);

	if (searchdata != NULL)
		printf("성공 : %d\n", searchdata->data);
	else
		printf("실패\n");

	return 0;
}