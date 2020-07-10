#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType* q) {
	return q->front == q->rear;
}

int is_full(QueueType* q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("큐가 포화상태입니다.");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다.");
		return;
	}
	
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void queue_print(QueueType* q) {
	int identifier = 1;
	for (int i = q->front+1; i <= q->rear; i++) {
		printf("큐의 %d번째 요소 : %d\n", identifier, q->queue[i]);
		identifier++;
	}
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");

	while (!is_full(&queue)) {
		printf("정수를 입력하시오:");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}

	printf("큐는 포화상태입니다.\n\n");
	printf("--데이터 삭제 단계--\n");

	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수: %d\n\n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.");

	return 0;
}