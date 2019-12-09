#pragma once
/*
Реализация очереди на базе односвязного списка.
Author: Nikolai Nenashev.
Moscow IPT 2019.
Для создания очереди используйте функцию create_deque
!!!!!НЕ ЗАБУДЬТЕ УДАЛИТЬ ОЧЕРДЬ ФУНКЦИЕЙ delte_deque!!!!!
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
Аргументы: указатель на очередь
Проверка на пустоту (Возвращает: 1 - непуста, 0 - пуста)
*/
int is_empty(deque* q);
/*
Аргументы: указатель на очередьб значение
Функция вставляет элемент в конец очереди.
*/
void push_back(deque* q, T value);
/*
Аргументы: указатель на очередь
Функция возвращает первый элемент
очереди. При этом элемент удаляется из очереди.
*/
T get_front(deque* q);
/*
Аргументы: указатель на очередь
Функция возвращает последний элемент
очереди. При этом элемент удаляется из очереди.
*/
T get_back(deque* q);
/*
Аргументы: указатель на очередь
Выводит очередь на экран.
*/
void print_deque(deque* q);
/*
Аргументы: указатель на очередь
Аналогична get_queue, только элемент не удаляется из
очереди.
*/
T touch_front(deque* q);
/*
Аргументы: указатель на очередь
Деинициализация (удаление) очереди.
*/
void delete_deque(deque* q);
/*
Аргументы: указатель на очередь, значение
Вставляет элемент в начало очереди.
Ничего не возвращает.
*/
void push_front(deque* q, T value);
/*
Аргументы: указатель на очередь
Выводит очередь на экран в обратном порядке.
*/
void print_reverse_deque(deque* q);
/*
Аргументы: указатель на очередь
Возвращает последний элемент очереди, 
при этом не удаляя его.
*/
T touch_back(deque* q);
/*
Инициализая и деинициализация (тест на утечки)
*/
int test1();
/*
Тест push и get back
*/
int test2();
/*
Тест push и get front
*/
int test3();
/*
Тест touch front
*/
int test4();
/*
Тест touch back
*/
int test5();
