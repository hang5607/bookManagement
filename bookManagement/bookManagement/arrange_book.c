#include<stdio.h>
#include "main.h"

FILE* fp;

void arrange_book()
{
	int i;
	int input;
	int count = 0; //�Է��� ����ü�� ����
	int size = 5;
	long f_size; // fp�� ũ��
	int f_count; //����ü�� ����� ����

	system("cls");

	fopen_s(&fp, "C:\\filedata\\book_list.dat", "rb");

	fseek(fp, 0, SEEK_END);
	f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	f_count = f_size / sizeof(book_info);

	book_list = (book_info*)malloc(sizeof(book_info) * f_count);
	fread(book_list, sizeof(book_info), f_count, fp);

	printf("---------------------------------\n");
	printf("     ���� ��� ���!!\n");
	printf("---------------------------------\n\n");

	for (i = 0; i < f_count; i++) {
		printf("����	  ����	  ��ȣ\n");
		printf("---------------------------\n");
		printf("%s   %s     %d   ===>     ", book_list[i].title, book_list[i].auth, book_list[i].m_count);
		if (book_list[i].stat == 0) {
			printf(" ���� ���� : �������� ���� \n\n ");
		}

		else {
			printf(" ���� ���� : ������ \n");
		}
	}
	fclose(fp);
	free(book_list);

	printf("���� ȭ������ ���÷��� 1���� �����ּ��� ==> ");
	scanf_s("%d", &input);
	if (input == 1)
	{
		system("cls");
		init();
	}
}