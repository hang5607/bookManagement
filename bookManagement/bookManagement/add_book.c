#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include "main.h"

int i = 0;
int input;
int count = 0; //입력한 구조체의 개수
int size = 5;
long f_size; // fp의 크기
int f_count; //구조체가 몇개인지 세기

FILE* fp;

void add_book()
{

	system("cls");
	book_list = (book_info*)malloc(size * sizeof(book_info)); //기억공간 할당받기

	while (1)
	{
		printf("도서를 추가하시겠습니까? <1. 도서추가   2. 종료>  ===>");
		scanf_s("%d", &input);
		if (input == 1)
		{
			if (i < size) {
				printf("제목과 저자를 입력하세요 : \n");
				scanf_s("%s", book_list[i].title, -1);
				scanf_s("%s", book_list[i].auth, -1);
				book_list[i].m_count = ++count;
				book_list[i].stat = 0;
				i++;
			}
			else {
				size += 5;
				book_list = (book_info*)realloc(book_list, sizeof(book_info) * size);
				printf("제목과 저자를 입력하세요 : \n");
				scanf_s("%s", book_list[i].title, -1);
				scanf_s("%s", book_list[i].auth, -1);
				book_list[i].m_count = ++count;
				i++;
			}
		}
		else if (input == 2)
		{
			break;
		}
	}
	fopen_s(&fp, "C:\\filedata\\book_list.dat", "wb");
	if (!fp) exit(1);

	fwrite(book_list, sizeof(book_info), count, fp);

	free(book_list);
	fclose(fp);

	system("cls");
	init();
}


