#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct student //����ü student�� ����
{
	char name[16]; //���ڿ� ũ�� 20¥�� ���� ����
	int age; //���̸� �־��� ����
	int math_score; //���� ������ �־��� ����
	int sum; //����� ���Ҷ� ����� �հ踦 ����
	int average; //����� ���� ����
};

int main() //���� �Լ�
{
	struct student arr[5]; //arr5�� �迭
	int i, j, temp; //i, j, temp����
	for (i = 0; i < 5; i++)//5�� �ݺ��ϴ� for��
	{
		printf("�̸� �Է� : \n"); scanf_s("%s", arr[i].name); //�̸� �Է� �޾� ����
		printf("���� �Է� : \n"); scanf_s("%d", &arr[i].age); //���̸� �Է� �޾� ����
		printf("���� ���� �Է� : \n"); scanf_s("%d", &arr[i].math_score); //���� ���� �Է� �޾� ����
	}
	for (i = 0; i < 5; i++) //5�� �ݺ��ϴ� for�� �Է¹��� ������ ����ϱ� ���ؼ�
	{
		arr[i].sum = arr[i].math_score;
		arr[i].average = arr[i].sum / 3;

		printf("---- %d��° �л� ���� �Է�  ---- \n", i + 1);
		printf("�̸� : %s \n", arr[i].name); //�̸� ���
		printf("���� : %d \n", arr[i].age); //���� ���
		printf("���� ���� : %d \n", arr[i].math_score); //���� ���� ���
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
		name, arr[i].average);
	}		printf("----  %d�� �л� ����  ----\n", i + 1);
	printf("�̸� : %s   ��� : %d \n", arr[i].
		return 0; //�Լ� �ʱ�ȭ
}