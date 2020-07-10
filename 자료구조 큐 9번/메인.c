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
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}

	a->stack[++(a->top)] = item;
}

void printstack(StackType* a) {
	printf("스택 출력 : ");
	for (int i = a->top; 0 <= i; i--) {
		printf("%d  ", a->stack[i]);
	}
	printf("\n");
}

element pop(StackType* a) {
	if (is_empty(a)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}

	return a->stack[a->top--];
}

element peek(StackType* a) {
	if (is_empty(a)) {
		fprintf(stderr, "스택공백에러");
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
	push(&q->input, item);	//push 호출
}

element dequeue(QueueType* q) {
	if (is_empty(&q->output)) {		//output이 비어있다면
		if (is_empty(&q->input)) {	//input도 비어있다면
			printf("입력된 값이 없습니다!");
			exit(1);
		}

		while (!is_empty(&q->input)) {	//input의 값을 가져옴
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
		printf("1.입력\t2.출력 : ");
		scanf("%d", &menu);

		if (menu == 1) {
			int value;
			printf("입력할 숫자를 입력하세요 : ");
			scanf("%d", &value);
			enqueue(&queue, value);
		}
		else if (menu == 2) {
			printf("꺼내진 값 : %d\n", dequeue(&queue));
		}
		else
			break;
	}
	printf("종료");

	return 0;
}