#ifndef M_HEADER_H
#define M_HEADER_H
#define MAX 256


/*
typedef struct book_info
{
	int m_count;//å�� ����ִ��� ����

	int stat; // ���� ���� �ĺ�. 0->�������� ���� 1->�뿩�� 2->�� ��ȣ�� å�� ����.

	char title[44]; // ���� ����

	char auth[32]; // ���� ����

	struct book_info* next;
}book_info;
*/

typedef struct book_info
{
	char title[44]; // ���� ����
	char auth[32]; // ���� ����
	int stat; // ���� ���� �ĺ�. 0->�������� ���� 1->�뿩�� 2->�� ��ȣ�� å�� ����.
	int m_count;//�Ϸù�ȣ
	int m_bookid; //book index
	struct user_info* user;
	//struct book_info* p;
}book_info;

typedef struct _user_info
{
	char id[20];
	char name[10];
	int m_count; //������ ����ִ��� ����
	int borr; // ������ �Ǽ�
	int stat; //���
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
