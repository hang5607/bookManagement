#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include "main.h"

int i = 0;
int input;
int count = 0; //�Է��� ����ü�� ����
int size = 5;
long f_size; // fp�� ũ��
int f_count; //����ü�� ����� ����

FILE* fp;

void add_book()
{

	system("cls");
	book_list = (book_info*)malloc(size * sizeof(book_info)); //������ �Ҵ�ޱ�

	while (1)
	{
		printf("������ �߰��Ͻðڽ��ϱ�? <1. �����߰�   2. ����>  ===>");
		scanf_s("%d", &input);
		if (input == 1)
		{
			if (i < size) {
				printf("����� ���ڸ� �Է��ϼ��� : \n");
				scanf_s("%s", book_list[i].title, -1);
				scanf_s("%s", book_list[i].auth, -1);
				book_list[i].m_count = ++count;
				book_list[i].stat = 0;
				i++;
			}
			else {
				size += 5;
				book_list = (book_info*)realloc(book_list, sizeof(book_info) * size);
				printf("����� ���ڸ� �Է��ϼ��� : \n");
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


