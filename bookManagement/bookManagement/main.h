#ifndef M_HEADER_H
#define M_HEADER_H
#define MAX 256


/*
typedef struct book_info
{
	int m_count;//책이 몇권있는지 세기

	int stat; // 도서 상태 식별. 0->도서관내 소장 1->대여중 2->이 번호는 책이 없음.

	char title[44]; // 도서 제목

	char auth[32]; // 도서 저자

	struct book_info* next;
}book_info;
*/

typedef struct book_info
{
	char title[44]; // 도서 제목
	char auth[32]; // 도서 저자
	int stat; // 도서 상태 식별. 0->도서관내 소장 1->대여중 2->이 번호는 책이 없음.
	int m_count;//일련번호
	int m_bookid; //book index
	struct user_info* user;
	//struct book_info* p;
}book_info;

typedef struct _user_info
{
	char id[20];
	char name[10];
	int m_count; //유저가 몇명있는지 세기
	int borr; // 빌려간 권수
	int stat; //등급
	struct book_info* m_uborr_list[5];
	//struct user_info* nextuser;
}user_info;

int* total_book;

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<malloc.h>
#include<time.h>

book_info* book_list;
user_info* user_list;

void init();
void add_book();
void arrange_book();
void search_book();
void search_user();
void add_user();
int borrow_book();
void return_book();

#endif
