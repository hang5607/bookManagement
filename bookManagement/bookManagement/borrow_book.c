#include<stdio.h>
#include "main.h"

FILE* fp;

int borrow_book()
{
	int i;
	int num1;
	int count = 0; //입력한 구조체의 개수
	int size = 5;
	long f_size; // fp의 크기
	int f_count; //구조체가 몇개인지 세기

	system("cls");

	printf("대여가능한 책은 아래와 같습니다.\n");

	fopen_s(&fp, "C:\\filedata\\book_list.dat", "rb");
	fseek(fp, 0, SEEK_END);
	f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	f_count = f_size / sizeof(book_info);

	book_list = (book_info*)malloc(sizeof(book_info) * f_count);
	fread(book_list, sizeof(book_info), f_count, fp);
	for (i = 0; i < f_count; i++) 
	{
		if (book_list[i].stat == 0)
		{
			printf("----------------------------------------");
			printf("\n%d. <제목: %s  저자: %s>\n", book_list[i].m_count, book_list[i].title, book_list[i].auth);
		}
	}
	printf("\n\n\n\n어떤 책을 빌리겠습니까?  ===> ");
	scanf_s("%d", &num1);
	for (i = 0; i < f_count; i++) {
		if (num1 == book_list[i].m_count)
		{
			book_list[i].stat = 1;
			printf("도서번호 %d가 대여되었습니다. ", book_list[i].m_count);
		}
	}
}