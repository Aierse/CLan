#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "����Ʈ.h" // �ܼ����Ḯ��Ʈ ����

int length(ListNode* list) {	
	int count = 0;

	for (ListNode* p = list; p != NULL; p = p->link) {
		count++;
	}

	return count;
}

int main(void) {
	ListNode* list = NULL;

	printf("����� ���� : ");
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		printf("��� #%d ������ : ", i + 1);
		int temp;
		scanf("%d", &temp);

		insert_node(&list, NULL, create_node(temp));
	}

	printf("���� ����Ʈ ����� ���� = %d", length(list));

	return 0;
}