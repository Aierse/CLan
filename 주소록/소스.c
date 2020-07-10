#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct {
	char name[SIZE];
	char address[SIZE];
	char mobilephone[SIZE];
	char desc[SIZE];
} PERSON;

PERSON get_record() {
	PERSON data;

	printf("�̸� : ");	gets_s(data.name, SIZE);
	printf("�ּ� : ");	gets_s(data.address, SIZE);
	printf("�޴��� : ");	gets_s(data.mobilephone, SIZE);
	printf("Ư¡ : ");	gets_s(data.desc, SIZE);

	return data;
}

void print_record(PERSON data) {
	printf("�̸� : %s\n", data.name);
	printf("�ּ� : %s\n", data.address);
	printf("�޴��� : %s\n", data.mobilephone);
	printf("Ư¡ : %s\n", data.desc);
}

int menu() {
	printf("========================\n");
	printf("1.�߰�\n");
	printf("2.����\n");
	printf("3.�˻�\n");
	printf("4.����\n");
	printf("========================\n");

	int temp;
	printf("�޴��� �����ϼ��� : ");
	scanf("%d", &temp);
	getchar();

	return temp;
}

void add_record(FILE* fp) {
	PERSON data = get_record();
	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
}

void update_record(FILE* fp) {
	int location = search_record(fp); //Ž������� ��ġ���� ����

	if (location == -1) {
		printf("�Է¿� �����߽��ϴ�.\n");
		return;
	}

	printf("========================\n");
	printf("������ ������ �Է��ϼ���.\n");

	PERSON data = get_record();
	fseek(fp, location, SEEK_SET); //location ��ġ�� �����
	fwrite(&data, sizeof(data), 1, fp);
}

//������ ��ġ�� �����ϱ� ���� int�� ��ȯ�ϰ� ����
int search_record(FILE* fp) {
	char name[SIZE];
	PERSON buffer;
	int location = 0; // Ž���� ���� ��ġ����

	fseek(fp, 0, SEEK_SET);

	printf("========================\n");
	printf("Ž���ϰ��� �ϴ� ����� �̸� : ");
	gets_s(name, SIZE);

	while (!feof(fp)) {
		fread(&buffer, sizeof(buffer), 1, fp);

		if (strcmp(buffer.name, name) == 0) {
			print_record(buffer);
			return location;
		}
		location += sizeof(buffer);
	}

	printf("Ž���� �����߽��ϴ�.\n");
	return -1;
}

int main(void) {
	FILE* fp = fopen("address.dat", "a+"); // ���� ����
	fclose(fp);

	if ((fp = fopen("address.dat", "r+")) == NULL) {
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�.");
		exit(1);
	}

	while (1) {
		int select = menu();
		switch (select) {
		case 1:
			add_record(fp);
			break;
		case 2:
			update_record(fp);
			break;
		case 3:
			search_record(fp);
			break;
		case 4:
			fclose(fp);
			printf("������ : 20174434 ������");
			return 0;
		}
	}
}