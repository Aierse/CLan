#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct student //구조체 student를 선언
{
	char name[16]; //문자열 크기 20짜리 변수 선언
	int age; //나이를 넣어줄 변수
	int math_score; //수학 성적을 넣어줄 변수
	int sum; //평균을 구할때 사용할 합계를 선언
	int average; //평균을 위한 변수
};

int main() //메인 함수
{
	struct student arr[5]; //arr5개 배열
	int i, j, temp; //i, j, temp선언
	for (i = 0; i < 5; i++)//5번 반복하는 for문
	{
		printf("이름 입력 : \n"); scanf_s("%s", arr[i].name); //이름 입력 받아 저장
		printf("나이 입력 : \n"); scanf_s("%d", &arr[i].age); //나이를 입력 받아 저장
		printf("수학 점수 입력 : \n"); scanf_s("%d", &arr[i].math_score); //수학 점수 입력 받아 저장
	}
	for (i = 0; i < 5; i++) //5번 반복하는 for문 입력받은 값들을 출력하기 위해서
	{
		arr[i].sum = arr[i].math_score;
		arr[i].average = arr[i].sum / 3;

		printf("---- %d번째 학생 정보 입력  ---- \n", i + 1);
		printf("이름 : %s \n", arr[i].name); //이름 출력
		printf("나이 : %d \n", arr[i].age); //나이 출력
		printf("수학 점수 : %d \n", arr[i].math_score); //수학 점수 출력
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[j].average < arr[j + 1].average)
			{
				temp = arr[j].average;
				arr[j].average = arr[j + 1].average;
				arr[j + 1].average = temp;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("----  %d번 학생 정보  ----\n", i + 1);
		printf("이름 : %s   평균 : %d \n", arr[i].name, arr[i].average);
	}		
	
	return 0; //함수 초기화
}
