#pragma once
/*
Реализация очереди на базе односвязного списка.
Author: Nikolai Nenashev.
Moscow IPT 2019.
*/
#include <stdlib.h>
#include <stdio.h>
#define OUT_OF_MEMORY -100
#define EMPTY_DEQUE -101
#define UNINITIALIZED -102
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
	struct Node_* prev;
} Node;
/*
Очередь (указатели на голову и конец списка)
*/
typedef struct deque_
{
	Node* head;
	Node* back;
} deque;
/*
Создание (инициализация) очереди.
*/
deque* create_deque();
/*
Проверка на пустоту (Возвращает: 1 - непуста, 0 - пуста)
*/
int is_empty(deque* q);
/*
Функция вставляет элемент в очередь.
*/
void push_back(deque* q, T value);
/*
Функция возвращает первый элемент
очереди. При этом элемент удаляется из очереди.
*/
T get_front(deque* q);
/*
Выводит очередь на экран.
*/
void print_deque(deque* q);
/*
Аналогична get_queue, только элемент не удаляется из
очереди.
*/
T touch_front(deque* q);
/*
Деинициализация (удаление) очереди.
*/
void delete_deque(deque* q);
/*
*/
void push_front(deque* q, T value);
/*
*/
void print_reverse_deque(deque* q);
/*
*/
T touch_back(deque* q);
