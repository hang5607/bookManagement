#include<stdio.h>
#include "main.h"

FILE* fp;

int borrow_book()
{
	int i;
	int num1;
	int count = 0; //�Է��� ����ü�� ����
	int size = 5;
	long f_size; // fp�� ũ��
	int f_count; //����ü�� ����� ����

	system("cls");

	printf("�뿩������ å�� �Ʒ��� �����ϴ�.\n");

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
			printf("\n%d. <����: %s  ����: %s>\n", book_list[i].m_count, book_list[i].title, book_list[i].auth);
		}
	}
	printf("\n\n\n\n� å�� �����ڽ��ϱ�?  ===> ");
	scanf_s("%d", &num1);
	for (i = 0; i < f_count; i++) {
		if (num1 == book_list[i].m_count)
		{
			book_list[i].stat = 1;
			printf("������ȣ %d�� �뿩�Ǿ����ϴ�. ", book_list[i].m_count);
		}
	}
}