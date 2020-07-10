#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* a) {
	a->top = -1;
}

int is_empty(StackType* a) {
	return a->top == -1;
}

int is_full(StackType* a) {
	return a->top == MAX_STACK_SIZE - 1;
}

void push(StackType* a, element item) {
	if (is_full(a)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}

	a->stack[++(a->top)] = item;
}

void printstack(StackType* a) {
	printf("���� ��� : ");
	for (int i = a->top; 0 <= i; i--) {
		printf("%d  ", a->stack[i]);
	}
	printf("\n");
}

element pop(StackType* a) {
	if (is_empty(a)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}

	return a->stack[a->top--];
}

element peek(StackType* a) {
	if (is_empty(a)) {
		fprintf(stderr, "���ð��鿡��");
		exit(1);
	}

	return a->stack[a->top];
}

typedef struct {
	StackType input;
	StackType output;
} QueueType;

void init_queue(QueueType* q) {
	init_stack(&q->input);
	init_stack(&q->output);
}

void enqueue(QueueType* q, element item) {
	push(&q->input, item);	//push ȣ��
}

element dequeue(QueueType* q) {
	if (is_empty(&q->output)) {		//output�� ����ִٸ�
		if (is_empty(&q->input)) {	//input�� ����ִٸ�
			printf("�Էµ� ���� �����ϴ�!");
			exit(1);
		}

		while (!is_empty(&q->input)) {	//input�� ���� ������
			push(&q->output, pop(&q->input));
		}
	}
	
	return pop(&q->output);
}

int main(void) {
	QueueType queue;
	init_queue(&queue);

	while (1) {
		int menu;
		printf("1.�Է�\t2.��� : ");
		scanf("%d", &menu);

		if (menu == 1) {
			int value;
			printf("�Է��� ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &value);
			enqueue(&queue, value);
		}
		else if (menu == 2) {
			printf("������ �� : %d\n", dequeue(&queue));
		}
		else
			break;
	}
	printf("����");

	return 0;
}