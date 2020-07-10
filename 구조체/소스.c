#include <stdio.h>
#define size(array) sizeof(array) / sizeof(array[0])

struct student {
	int number;
	char name[20];
	double grade;
};

int main(void) {
	struct student list[] = {
		{20180001, "È«±æµ¿", 4.2},
		{20180002, "±èÃ¶¼ö", 3.2},
		{20180003, "±è¿µÈñ", 3.9}
	};

	struct student superstudent = list[0];

	for (int i = 0; i < size(list); i++) {
		if (list[i].grade > superstudent.grade)
			superstudent = list[i];
	}

	printf("ÆòÁ¡ÀÌ °¡Àå ³ôÀº ÇĞ»ıÀº (ÀÌ¸§ : %s, ÇĞ¹ø : %d ÆòÁ¡ : %f )ÀÔ´Ï´Ù.\n", superstudent.name, superstudent.number, superstudent.grade);
	printf("Á¦ÀÛÀÚ : 20174434 Á¶À±Çõ");

	return 0;
}