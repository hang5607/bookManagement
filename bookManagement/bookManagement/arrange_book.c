#include<stdio.h>
#include "main.h"

FILE* fp;

void arrange_book()
{
	int i;
	int input;
	int count = 0; //입력한 구조체의 개수
	int size = 5;
	long f_size; // fp의 크기
	int f_count; //구조체가 몇개인지 세기

	system("cls");

	fopen_s(&fp, "C:\\filedata\\book_list.dat", "rb");

	fseek(fp, 0, SEEK_END);
	f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	f_count = f_size / sizeof(book_info);

	book_list = (book_info*)malloc(sizeof(book_info) * f_count);
	fread(book_list, sizeof(book_info), f_count, fp);

	printf("---------------------------------\n");
	printf("     도서 목록 출력!!\n");
	printf("---------------------------------\n\n");

	for (i = 0; i < f_count; i++) {
		printf("제목	  저자	  번호\n");
		printf("---------------------------\n");
		printf("%s   %s     %d   ===>     ", book_list[i].title, book_list[i].auth, book_list[i].m_count);
		if (book_list[i].stat == 0) {
			printf(" 대출 여부 : 도서관내 소장 \n\n ");
		}

		else {
			printf(" 대출 여부 : 대출중 \n");
		}
	}
	fclose(fp);
	free(book_list);

	printf("메인 화면으로 가시려면 1번을 눌러주세요 ==> ");
	scanf_s("%d", &input);
	if (input == 1)
	{
		system("cls");
		init();
	}
}