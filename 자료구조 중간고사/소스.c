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
		fprintf(stderr, "����!");
		exit(1);
	}

	ListNode* head = list->last->link; // ù�κ�
	ListNode* p = head; // ó������ �̵�

	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head);

	printf("\n");
}

ListNode* search(CListType* list, element data) {
	if (list == NULL) {
		fprintf(stderr, "����!");
		exit(1);
	}

	ListNode* head = list->last->link;
	ListNode* p = head;

	do {
		if (p->data == data)
			return p;

		p = p->link;
	} while (p != head);

	return NULL; // Ž������� ������ NULL ��ȯ
}

int get_size(CListType* list) {
	if (list == NULL)
		return 0;

	ListNode* head = list->last->link; // ù�κ�
	ListNode* p = head;
	
	int count = 0; // ������ ���� �����ǹǷ� 1���� ����

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
	printf("����Ʈ ũ�� : %d\n", get_size(&list));

	ListNode* searchdata = search(&list, 3);

	if (searchdata != NULL)
		printf("���� : %d\n", searchdata->data);
	else
		printf("����\n");

	return 0;
}