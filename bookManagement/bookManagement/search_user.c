#include "main.h"

FILE* fp;

void search_user()
{
	int i;
	int input;
	long f_size; // fp�� ũ��
	int f_count; //����ü�� ����� ����

	system("cls");

	fopen_s(&fp, "C:\\filedata\\user_list.dat", "rb");

	fseek(fp, 0, SEEK_END);
	f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	f_count = f_size / sizeof(user_info);

	user_list = (user_info*)malloc(sizeof(user_info) * f_count);
	fread(user_list, sizeof(user_info), f_count, fp);

	printf("-----------------------------------------\n");
	printf("     ȸ�� ��� ���!!\n");
	printf("-----------------------------------------\n\n");

	for (i = 0; i < f_count; i++)
	{
		printf("<ID �̸� ��ȣ> ===> ");
		printf("<%s   %s   %d>   \n", user_list[i].id, user_list[i].name, user_list[i].m_count);
		printf("-----------------------------------------\n");

	}

	fclose(fp);
	free(user_list);

	printf("���� ȭ������ ���÷��� 1���� �����ּ��� ==> ");
	scanf_s("%d", &input);
	if (input == 1)
	{
		system("cls");
		init();
	}
	getch();
}