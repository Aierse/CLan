#include <stdio.h>
#include <time.h>

void getSensorData(double* p) {
	p[0] = rand() % 100;
	p[1] = rand() % 100;
	p[2] = rand() % 100;
}
int main(void) {
	srand(time(NULL));

	double sensorData[3];
	getSensorData(sensorData);

	printf("왼쪽 센서와 장애물과의 거리: %lf \n", sensorData[0]);
	printf("중간 센서와 장애물과의 거리: %lf \n", sensorData[1]);
	printf("오른쪽 센서와 장애물과의 거리: %lf \n", sensorData[2]);
	printf("제작자 : 20174434 조윤혁");
	return 0;
}