#pragma once
/*
���������� ������� �� ���� ������������ ������.
Author: Nikolai Nenashev.
Moscow IPT 2019.
*/
#include <stdlib.h>
#include <stdio.h>
#define OUT_OF_MEMORY -100
#define EMPTY_DEQUE -101
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
�������� �� ������� (����������: 1 - �������, 0 - �����)
*/
int is_empty(deque* q);
/*
������� ��������� ������� � �������.
*/
void push_back(deque* q, T value);
/*
������� ���������� ������ �������
�������. ��� ���� ������� ��������� �� �������.
*/
T get_front(deque* q);
/*
������� ������� �� �����.
*/
void print_deque(deque* q);
/*
���������� get_queue, ������ ������� �� ��������� ��
�������.
*/
T touch_front(deque* q);
/*
��������������� (��������) �������.
*/
void delete_deque(deque* q);

