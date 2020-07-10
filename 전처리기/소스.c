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
	printf("area(%f)가 호출되었음\n", radius);
#endif
#endif

	return PI * SQUARE(radius);
}

int main(void) {
#ifdef USA
	printf("Please enter radius of a circle(inch) : ");
#else
	printf("원의 반지름을 입력하시오: ");
#endif

	double radius;
	scanf("%lf", &radius);

#ifdef USA
	printf("area of the circle is %f\n", area(radius));
#else
	printf("원의 면적은 %f입니다.\n", area(radius));
#endif
}