#include <stdio.h>

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

void insert_first(ListNode** head, ListNode* node) {
	if (*head == NULL) {
		*head = node;
		node->link = node;
	}
	else {
		node->link = (*head)->link;
		(*head)->link = node;
	}
}

void insert_last(ListNode** head, ListNode* node) {
	if (*head == NULL) {
		*head = node;
		node->link = node;
	}
	else {
		node->link = (*head)->link;
		(*head)->link = node;
		*head = node;
	}
}

void display(ListNode* list) {
	ListNode* head = list->link; // ù�κ�
	ListNode* p = head; // ó������ �̵�

	while (p->link != head) { // ������ ���� ������
		printf("%d -> ", p->data);
		p = p->link;
	}

	printf("%d -> ", p->data); // ������ ��� ���
	printf("\n");
}

int main(void) {
	ListNode* list = NULL;

	insert_first(&list, create_node(3));
	insert_first(&list, create_node(2));
	insert_first(&list, create_node(1));

	display(list);

	return 0;
}