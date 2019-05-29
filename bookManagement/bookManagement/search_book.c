#include "main.h"

void print_book(book_info* book);

FILE* fp;

void search_book()
{
	long f_size; // fp의 크기
	int f_count; //구조체가 몇개인지 세기
	int i, j;
	int temp;
	int result = 0;
	char str[42];

	fopen_s(&fp, "C:\\filedata\\book_list.dat", "rb");
	fseek(fp, 0, SEEK_END);
	f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	f_count = f_size / sizeof(book_info);

	book_list = (book_info*)malloc(sizeof(book_info) * f_count);

	fread(book_list, sizeof(book_info), f_count, fp);

	//for (i = 0; i < f_count; i++) // 도서 목록 출력
	//	printf("%s   %s   %d\n", book_list[i].title, book_list[i].auth, book_list[i].m_count);

	printf("무엇으로 검색하시겠습니까?\n 1.제목  2.저자  ");
	scanf_s("%d", &i);
	if (i == 1)
	{
		printf("검색 키워드를 입력하십시오 : ");
		scanf_s("%s", str, -1);

		//for (j = 0; j < book_list[j].m_count; j++)
		for (j = 0; j < f_count; j++)
		{
			temp = strcmp(str, book_list[j].title);
			if (temp == 0)
			{
				print_book(&book_list[j]);
				result++;
			}
		}
	}
	else if (i == 2)
	{
		printf("검색 키워드를 입력하십시오 : ");
		scanf_s("%s", str, -1);
		for (j = 0; j < book_list[j].m_count; j++)
		{
			temp = strcmp(str, book_list[j].auth);
			if (temp == 0)
			{
				print_book(&book_list[j]);
				result++;

			}
		}
	}
	else
	{
		printf("잘못된 명령입니다.\n");
		return 0;
	}
	if (result > 0)
	{
		printf("검색이 완료되었습니다. \n");
	}
	else
	{
		printf("일치하는 검색어가 없습니다. \n");
	}
}

void print_book(book_info* book)

{
	printf("제목 : %s \n", book->title);
	printf("저자 : %s \n", book->auth);
	//1번일때 다시 검색 2번일때 메인화면 추가
}