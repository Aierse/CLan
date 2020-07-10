#include <stdio.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct LinkedQueueType {
	struct QueueNode* front, * rear;
} LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return q->front == NULL;
}

void enqueue(LinkedQueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;

	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

element dequeue(LinkedQueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있음\n");
		exit(1);
	}

	QueueNode* temp = q->front;
	element data = q->front->data;
	
	q->front = q->front->link;
	free(temp);

	return data;
}

void display(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p->link != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("%d\n", p->data);
}

int main(void) {
	LinkedQueueType q;

	init(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	display(&q);

	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));
	printf("dequeue() = %d\n", dequeue(&q));

	return 0;
}