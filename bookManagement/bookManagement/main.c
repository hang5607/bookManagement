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
	printf("\n1.회원 추가 2.회원 목록 출력 3.도서 추가 4.도서 목록 출력\n\n5.도서 검색 6.도서 대여 7.도서 반납 8.도서관 종료\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n원하는 업무를 입력하세요==> ");
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
		printf("\n---도서관을 종료합니다----\n");
		break;
	}
}