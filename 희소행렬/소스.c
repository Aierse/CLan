#include <stdio.h>
#define MAX_TERM 10
#define ROW 3
#define COL 3

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct {
	element data[MAX_TERM];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

SparseMatrix sparse_matrix_add(SparseMatrix a, SparseMatrix b) {
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "희소행렬 크기 에러\n");
		exit(1);
	}

	SparseMatrix c;
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	int ca = 0, cb = 0, cc = 0;

	while (ca < a.terms && cb < b.terms) {
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;

		if (inda < indb) {
			c.data[cc++] = a.data[ca++];
		}
		else if (inda == indb) {
			if (a.data[ca].value + b.data[cb].value != 0) {
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else {
				ca++;
				cb++;
			}
		}
		else {
			c.data[cc++] = b.data[cb++];
		}
	}

	while (ca < a.terms)
		c.data[cc++] = a.data[ca++];
	while (cb < b.terms)
		c.data[cc++] = b.data[cb++];

	c.terms = cc;

	return c;
}

SparseMatrix sparse_matrix_sub(SparseMatrix a, SparseMatrix b) {
	// 뺄 행렬 부호 전환
	for (int i = 0; i < b.terms; i++) {
		b.data[i].value = -b.data[i].value;
	}

	return sparse_matrix_add(a, b); // 덧셈 호출
}

void printmatrix(SparseMatrix temp) {
	int board[ROW][COL] = { 0 }; //행렬의 형태로 변환하기 위해 틀 생성
	for (int i = 0; i < temp.terms; i++) { // 위치에 맞게 값을 입력
		board[temp.data[i].row][temp.data[i].col] = temp.data[i].value;
	}
	// 보드 출력
	for (int y = 0; y < COL; y++) {
		for (int x = 0; x < ROW; x++) {
			printf("%3d\t", board[x][y]);
		}
		printf("\n\n");
	}
}

int main(void) {
	SparseMatrix m1 = { {{1,1,5}, {2,2,9}}, 3, 3, 2 };
	SparseMatrix m2 = { {{0,0,5}, {2,2,9}}, 3, 3, 2 };

	printf("=====================\n");
	printmatrix(m1);
	printf("\t  +\n\n");
	printmatrix(m2);
	printf("      덧셈 결과\n\n");
	printmatrix(sparse_matrix_add(m1, m2));
	printf("=====================\n");
	printf("=====================\n");
	printmatrix(m1);
	printf("\t  -\n\n");
	printmatrix(m2);
	printf("      뺄셈 결과\n\n");
	printmatrix(sparse_matrix_sub(m1, m2));
	printf("=====================\n");

	return 0;
}