#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define USA
#define DEBUG

#ifndef PI
#define PI 3.141592
#endif

#ifndef SQUARE
#define SQUARE(r) (r * r)
#endif

double area(double radius) {
#ifdef DEBUG
#ifdef USA
	printf("area(%f) is called\n", radius);
#else
	printf("area(%f)�� ȣ��Ǿ���\n", radius);
#endif
#endif

	return PI * SQUARE(radius);
}

int main(void) {
#ifdef USA
	printf("Please enter radius of a circle(inch) : ");
#else
	printf("���� �������� �Է��Ͻÿ�: ");
#endif

	double radius;
	scanf("%lf", &radius);

#ifdef USA
	printf("area of the circle is %f\n", area(radius));
#else
	printf("���� ������ %f�Դϴ�.\n", area(radius));
#endif
}