#include "main.h"

void print_book(book_info* book);

FILE* fp;

void search_book()
{
	long f_size; // fp�� ũ��
	int f_count; //����ü�� ����� ����
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

	//for (i = 0; i < f_count; i++) // ���� ��� ���
	//	printf("%s   %s   %d\n", book_list[i].title, book_list[i].auth, book_list[i].m_count);

	printf("�������� �˻��Ͻðڽ��ϱ�?\n 1.����  2.����  ");
	scanf_s("%d", &i);
	if (i == 1)
	{
		printf("�˻� Ű���带 �Է��Ͻʽÿ� : ");
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
		printf("�˻� Ű���带 �Է��Ͻʽÿ� : ");
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
		printf("�߸��� ����Դϴ�.\n");
		return 0;
	}
	if (result > 0)
	{
		printf("�˻��� �Ϸ�Ǿ����ϴ�. \n");
	}
	else
	{
		printf("��ġ�ϴ� �˻�� �����ϴ�. \n");
	}
}

void print_book(book_info* book)

{
	printf("���� : %s \n", book->title);
	printf("���� : %s \n", book->auth);
	//1���϶� �ٽ� �˻� 2���϶� ����ȭ�� �߰�
}