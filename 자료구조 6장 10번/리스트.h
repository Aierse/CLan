#pragma once
#include <stdio.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* create_node(element value) {
	ListNode* temp = malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;

	return temp;
}

void insert_node(ListNode** head, ListNode* p, ListNode* added) {
	if (*head == NULL)
		*head = added;
	else if (p == NULL) {
		added->link = *head;
		*head = added;
	}
	else {
		added->link = p->link;
		p->link = added;
	}
}

void insert(ListNode** head, int location, ListNode* added) {
	ListNode* p = *head;

	printf("%p\n", p);
	for (int i = 0; i < location; i++) {
		p = p->link;
	}

	printf("%p\n", p);
	insert_node(head, p, added);
}

void remove_node(ListNode** head, ListNode* p, ListNode* removed) {
	if (p == NULL)
		*head = (*head)->link;
	else
		p->link = removed->link;

	free(removed);
}

ListNode* search(ListNode* head, int x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x)
			return p;

		p = p->link;
	}

	return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2) {
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	ListNode* p = head1;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = head2;

	return head1;
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

void display(ListNode* p) {
	printf("%d", p->data);
	p = p->link;
	while (p != NULL) {
		printf(" -> %d", p->data);
		p = p->link;
	}
	printf("\n");
}