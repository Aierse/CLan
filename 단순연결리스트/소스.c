#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	if (head == NULL)
		return NULL;

	ListNode* removed;
	removed = head;
	head = head->link;
	free(removed);

	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d ->", p->data);
	}

	printf("NULL\n");
}

void display(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}

int main(void) {
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head, i);
		print_list(head);
	}

	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 1);

	display(head);


	return 0;
}