#pragma once
/*
���������� ������� �� ���� ������������ ������.
Author: Nikolai Nenashev.
Moscow IPT 2019.
*/
#include <stdlib.h>
#include <stdio.h>
#define OUT_OF_MEMORY -100
#define EMPTY_QUEUE -101
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
typedef struct queue_
{
	Node* head;
	Node* back;
} queue;
/*
�������� (�������������) �������.
*/
queue* create_q();
/*
�������� �� ������� (����������: 1 - �������, 0 - �����)
*/
int is_empty(queue* q);
/*
������� ��������� ������� � �������.
*/
void insert_queue(queue* q, T value);
/*
������� ���������� ������ �������
�������. ��� ���� ������� ��������� �� �������.
*/
T get_queue(queue* q);
/*
������� ������� �� �����.
*/
void print_queue(queue* q);
/*
���������� get_queue, ������ ������� �� ��������� ��
�������.
*/
T touch(queue* q);
/*
��������������� (��������) �������.
*/
void delete_queue(queue* q);

