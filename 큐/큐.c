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
		printf("ť�� ��ȭ�����Դϴ�.");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("ť�� ��������Դϴ�.");
		return;
	}
	
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void queue_print(QueueType* q) {
	int identifier = 1;
	for (int i = q->front+1; i <= q->rear; i++) {
		printf("ť�� %d��° ��� : %d\n", identifier, q->queue[i]);
		identifier++;
	}
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");

	while (!is_full(&queue)) {
		printf("������ �Է��Ͻÿ�:");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}

	printf("ť�� ��ȭ�����Դϴ�.\n\n");
	printf("--������ ���� �ܰ�--\n");

	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("������ ����: %d\n\n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.");

	return 0;
}