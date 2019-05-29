#include<stdio.h>
#include "main.h"

FILE* fp;

void add_user()
{
	int size = 5;
	int input;
	int i = 0;
	int count = 0; //입력한 구조체의 개수

	system("cls");
	user_list = (user_info*)malloc(size * sizeof(user_info));
	while (1)
	{
		printf("ID를 추가하시겠습니까? <1.추가   2.종료>  ===>");
		scanf_s("%d", &input);
		if (input == 1)
		{
			if (i < size)
			{
				printf("ID와 이름을 입력하세요 ===> \n");
				scanf_s("%s", user_list[i].id, -1);
				scanf_s("%s", user_list[i].name, -1);
				user_list[i].m_count = ++count;
				user_list[i].stat = 1;
				i++;
			}
			else
			{
				size += 5;
				user_list = (user_info*)realloc(user_list, sizeof(user_info) * size);
				printf("ID와 이름을 입력하세요 ===> \n");
				scanf_s("%s", user_list[i].id, -1);
				scanf_s("%s", user_list[i].name, -1);
				user_list[i].m_count == ++count;
				user_list[i].stat = 1;
				i++;
			}
		}
		else if (input == 2)
		{
			break;
		}
	}
	fopen_s(&fp, "C:\\filedata\\user_list.dat", "wb");
	if (!fp) exit(1);
	fwrite(user_list, sizeof(user_info), count, fp);

	free(book_list);
	fclose(fp);

	system("cls");
	init();
}