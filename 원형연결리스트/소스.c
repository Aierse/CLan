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
	ListNode* head = list->link; // 첫부분
	ListNode* p = head; // 처음으로 이동

	while (p->link != head) { // 마지막 노드는 누락됨
		printf("%d -> ", p->data);
		p = p->link;
	}

	printf("%d -> ", p->data); // 마지막 노드 출력
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