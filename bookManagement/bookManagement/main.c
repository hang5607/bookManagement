#include<stdio.h>
#include "main.h"

void init();

void main()
{
	init();
	getch();
}

void init()
{
	int num;

	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n1.ȸ�� �߰� 2.ȸ�� ��� ��� 3.���� �߰� 4.���� ��� ���\n\n5.���� �˻� 6.���� �뿩 7.���� �ݳ� 8.������ ����\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n���ϴ� ������ �Է��ϼ���==> ");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		add_user();
		break;
	case 2:
		search_user();
		break;
	case 3:
		add_book();
		break;
	case 4:
		arrange_book();
		break;
	case 5:
		search_book();
		break;
	case 6:
		borrow_book();
		break;
	case 7:
		return_book();
		break;
		/*
		case 8:
			return_book();
			break;

		case 9:
			borrow_book();
			break;
		case 10:
			return_book();
			break;*/
	default:
		printf("\n---�������� �����մϴ�----\n");
		break;
	}
}