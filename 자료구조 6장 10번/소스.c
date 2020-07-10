#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "리스트.h" // 단순연결리스트 구현

int length(ListNode* list) {	
	int count = 0;

	for (ListNode* p = list; p != NULL; p = p->link) {
		count++;
	}

	return count;
}

int main(void) {
	ListNode* list = NULL;

	printf("노드의 개수 : ");
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		int temp;
		scanf("%d", &temp);

		insert_node(&list, NULL, create_node(temp));
	}

	printf("연결 리스트 노드의 개수 = %d", length(list));

	return 0;
}