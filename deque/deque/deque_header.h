#pragma once
/*
���������� ������� �� ���� ������������ ������.
Author: Nikolai Nenashev.
Moscow IPT 2019.
��� �������� ������� ����������� ������� create_deque
!!!!!�� �������� ������� ������ �������� delte_deque!!!!!
*/
#include <stdlib.h>
#include <stdio.h>
#define OUT_OF_MEMORY -100
#define EMPTY_DEQUE -101
#define UNINITIALIZED -102
/*
������� ������.
*/
typedef int T;
/*
���� ������
*/
typedef struct Node_
{
	T value;
	struct Node_* next;
	struct Node_* prev;
} Node;
/*
������� (��������� �� ������ � ����� ������)
*/
typedef struct deque_
{
	Node* head;
	Node* back;
} deque;
/*
�������� (�������������) �������.
*/
deque* create_deque();
/*
���������: ��������� �� �������
�������� �� ������� (����������: 1 - �������, 0 - �����)
*/
int is_empty(deque* q);
/*
���������: ��������� �� �������� ��������
������� ��������� ������� � ����� �������.
*/
void push_back(deque* q, T value);
/*
���������: ��������� �� �������
������� ���������� ������ �������
�������. ��� ���� ������� ��������� �� �������.
*/
T get_front(deque* q);
/*
���������: ��������� �� �������
������� ���������� ��������� �������
�������. ��� ���� ������� ��������� �� �������.
*/
T get_back(deque* q);
/*
���������: ��������� �� �������
������� ������� �� �����.
*/
void print_deque(deque* q);
/*
���������: ��������� �� �������
���������� get_queue, ������ ������� �� ��������� ��
�������.
*/
T touch_front(deque* q);
/*
���������: ��������� �� �������
��������������� (��������) �������.
*/
void delete_deque(deque* q);
/*
���������: ��������� �� �������, ��������
��������� ������� � ������ �������.
������ �� ����������.
*/
void push_front(deque* q, T value);
/*
���������: ��������� �� �������
������� ������� �� ����� � �������� �������.
*/
void print_reverse_deque(deque* q);
/*
���������: ��������� �� �������
���������� ��������� ������� �������, 
��� ���� �� ������ ���.
*/
T touch_back(deque* q);
/*
����������� � ��������������� (���� �� ������)
*/
int test1();
/*
���� push � get back
*/
int test2();
/*
���� push � get front
*/
int test3();
/*
���� touch front
*/
int test4();
/*
���� touch back
*/
int test5();
