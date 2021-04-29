#include <stdio.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	struct QueueNode* front, * rear;
} Queue;

void init(Queue* q) {
	q->front = q->rear = NULL;
}

int is_empty(Queue* q) {
	return q->front == NULL;
}

void enqueue(Queue* q, element item) {
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

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "Å¥°¡ ºñ¾îÀÖÀ½\n");
		exit(1);
	}

	QueueNode* temp = q->front;
	element data = q->front->data;
	
	q->front = q->front->link;
	free(temp);

	return data;
}

void display(Queue* q) {
	QueueNode* p;
	for (p = q->front; p->link != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("%d\n", p->data);
}

int main(void) {
	Queue q;

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
