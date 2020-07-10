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

	printf("이름 : ");	gets_s(data.name, SIZE);
	printf("주소 : ");	gets_s(data.address, SIZE);
	printf("휴대폰 : ");	gets_s(data.mobilephone, SIZE);
	printf("특징 : ");	gets_s(data.desc, SIZE);

	return data;
}

void print_record(PERSON data) {
	printf("이름 : %s\n", data.name);
	printf("주소 : %s\n", data.address);
	printf("휴대폰 : %s\n", data.mobilephone);
	printf("특징 : %s\n", data.desc);
}

int menu() {
	printf("========================\n");
	printf("1.추가\n");
	printf("2.수정\n");
	printf("3.검색\n");
	printf("4.종료\n");
	printf("========================\n");

	int temp;
	printf("메뉴를 선택하세요 : ");
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
	int location = search_record(fp); //탐색결과의 위치정보 저장

	if (location == -1) {
		printf("입력에 실패했습니다.\n");
		return;
	}

	printf("========================\n");
	printf("수정할 내용을 입력하세요.\n");

	PERSON data = get_record();
	fseek(fp, location, SEEK_SET); //location 위치에 덮어씌움
	fwrite(&data, sizeof(data), 1, fp);
}

//정해진 위치를 수정하기 위해 int를 반환하게 수정
int search_record(FILE* fp) {
	char name[SIZE];
	PERSON buffer;
	int location = 0; // 탐색한 값의 위치정보

	fseek(fp, 0, SEEK_SET);

	printf("========================\n");
	printf("탐색하고자 하는 사람의 이름 : ");
	gets_s(name, SIZE);

	while (!feof(fp)) {
		fread(&buffer, sizeof(buffer), 1, fp);

		if (strcmp(buffer.name, name) == 0) {
			print_record(buffer);
			return location;
		}
		location += sizeof(buffer);
	}

	printf("탐색에 실패했습니다.\n");
	return -1;
}

int main(void) {
	FILE* fp = fopen("address.dat", "a+"); // 파일 생성
	fclose(fp);

	if ((fp = fopen("address.dat", "r+")) == NULL) {
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.");
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
			printf("제작자 : 20174434 조윤혁");
			return 0;
		}
	}
}