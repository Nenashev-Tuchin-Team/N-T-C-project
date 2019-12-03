#pragma once
/*
Реализация очереди на базе односвязного списка.
Author: Nikolai Nenashev.
Moscow IPT 2019.
*/
#include <stdlib.h>
#include <stdio.h>
#define OUT_OF_MEMORY -100
#define EMPTY_QUEUE -101
/*
Дефайны ошибок.
*/
typedef int T;
/*
Узел списка
*/
typedef struct Node_
{
	T value;
	struct Node_* next;
} Node;
/*
Очередь (указатели на голову и конец списка)
*/
typedef struct queue_
{
	Node* head;
	Node* back;
} queue;
/*
Создание (инициализация) очереди.
*/
queue* create_q();
/*
Проверка на пустоту (Возвращает: 1 - непуста, 0 - пуста)
*/
int is_empty(queue* q);
/*
Функция вставляет элемент в очередь.
*/
void insert_queue(queue* q, T value);
/*
Функция возвращает первый элемент
очереди. При этом элемент удаляется из очереди.
*/
T get_queue(queue* q);
/*
Выводит очередь на экран.
*/
void print_queue(queue* q);
/*
Аналогична get_queue, только элемент не удаляется из
очереди.
*/
T touch(queue* q);
/*
Деинициализация (удаление) очереди.
*/
void delete_queue(queue* q);

