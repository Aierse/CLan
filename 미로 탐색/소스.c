#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

static char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

typedef struct {
	short r;
	short c;
} element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

static element here = { 1, 0 };
static element entry = { 1, 0 };

void init_stack(StackType* a) {
	a->top = -1;
}

int is_empty(StackType* a) {
	return a->top == -1;
}

int is_full(StackType * a) {
	return a->top == MAX_STACK_SIZE - 1;
}

void push(StackType * a, element item) {
	if (is_full(a)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}

	else a->stack[++(a->top)] = item;
}

void printStack(StackType * a) {
	for (int i = a->top; 0 <= i; i--) {
		printf(" %d ��° ���� { �� : %d, �� : %d }\n", i, (a->stack[i]).r, (a->stack[i]).c);
	}
}

element pop(StackType * a) {
	if (is_empty(a)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else	return a->stack[(a->top)--];
}

element peek(StackType * a) {
	if (is_empty(a)) {
		fprintf(stderr, "���ð��鿡��");
		exit(1);
	}

	else
		return a->stack[a->top];
}

void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0)	return;

	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char m[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf(" %c", maze[r][c]);
		}
		printf("\n");
	}
}



int main() {
	int r, c;
	StackType s;
	init_stack(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';

		maze_print(maze);

		push_loc(&s, r - 1, c); //��
		push_loc(&s, r + 1, c); //�Ʒ�
		push_loc(&s, r, c - 1); //����
		push_loc(&s, r, c + 1); //������

		printStack(&s);

		if (is_empty(&s)) {
			printf("����\n");
			return 0;
		}
		else {
			here = pop(&s);
		}
	}

	printf("����\n");
	printf("������ : 20174434 ������");

	return 0;
}