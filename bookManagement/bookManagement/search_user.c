#include "main.h"

FILE* fp;

void search_user()
{
	int i;
	int input;
	long f_size; // fp의 크기
	int f_count; //구조체가 몇개인지 세기

	system("cls");

	fopen_s(&fp, "C:\\filedata\\user_list.dat", "rb");

	fseek(fp, 0, SEEK_END);
	f_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	f_count = f_size / sizeof(user_info);

	user_list = (user_info*)malloc(sizeof(user_info) * f_count);
	fread(user_list, sizeof(user_info), f_count, fp);

	printf("-----------------------------------------\n");
	printf("     회원 목록 출력!!\n");
	printf("-----------------------------------------\n\n");

	for (i = 0; i < f_count; i++)
	{
		printf("<ID 이름 번호> ===> ");
		printf("<%s   %s   %d>   \n", user_list[i].id, user_list[i].name, user_list[i].m_count);
		printf("-----------------------------------------\n");

	}

	fclose(fp);
	free(user_list);

	printf("메인 화면으로 가시려면 1번을 눌러주세요 ==> ");
	scanf_s("%d", &input);
	if (input == 1)
	{
		system("cls");
		init();
	}
	getch();
}