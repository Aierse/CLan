#include <stdio.h>
#define size(array) sizeof(array) / sizeof(array[0])

struct student {
	int number;
	char name[20];
	double grade;
};

int main(void) {
	struct student list[] = {
		{20180001, "ȫ�浿", 4.2},
		{20180002, "��ö��", 3.2},
		{20180003, "�迵��", 3.9}
	};

	struct student superstudent = list[0];

	for (int i = 0; i < size(list); i++) {
		if (list[i].grade > superstudent.grade)
			superstudent = list[i];
	}

	printf("������ ���� ���� �л��� (�̸� : %s, �й� : %d ���� : %f )�Դϴ�.\n", superstudent.name, superstudent.number, superstudent.grade);
	printf("������ : 20174434 ������");

	return 0;
}