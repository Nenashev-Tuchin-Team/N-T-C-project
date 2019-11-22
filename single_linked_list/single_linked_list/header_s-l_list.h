#pragma once
#include<stdlib.h>
#include<stdio.h>
/*
Структура, описывающая узел списка
*/
typedef struct Node_
{
	int value;
	struct Node_* next;
} Node;
/*
Аргументы: значение головы списка.
Функция создает голову списка с 
указанным значением и возвращает
указатель нее.
*/
Node* create_list(int value)
{
	Node* head = NULL;
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}
	head->value = value;
	head->next = 0;
	return head;
}
/*
Аргументы:адрес указателя на голову списка, передаваемое значение
Функция, добавляющая элемент в голову списка.
Возвращает 1 в случае успешного добавления элемента
И 0 в случае неуспешного.
*/
int push_head(Node** head, int value)
{
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		return 0;
	}
	tmp->value = value;
	tmp->next = (*head);
	(*head) = tmp;
	return 1;
}
/*
Аргументы: адрес указателя на голову списка
Функция удаляет голову списка.
В случае успеха возвращает 1, иначе - 0.
*/
int pop_head(Node** head)
{
	if ((*head) == NULL)
	{
		return 0;
	}
	Node* prev_head = (*head);
	(*head) = (*head)->next;
	free(prev_head);
	return 1;
}
/*
Аргументы: указатель на голову списка, 
номер элемента, который нужно найти
Функция возвращает NULL значение в случае когда N больше
длины списка, иначе возвращает указатель на последний элемент.
*/
Node* get_N(Node* head, int n)
{
	int i = 0;
	Node* curr = head;
	while (i < n && curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return curr;
}
/*
Аргументы: указатель на голову списка
Функция возвращает указатель на конец списка.
*/
Node* get_back(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node* curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return curr;
}
/*
Аргументы: указатель на голову списка, значение
Функция добавляет элемент в конец списка.
Возвращает 1 в случае успеха и 0 в противном случае. 
*/
int push_back(Node* head, int value)
{
	Node* back = get_back(head);
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		return 0;
	}
	tmp->value = value;
	tmp->next = NULL;
	back->next = tmp;
	return 1;
}
/*
Аргументы: указатель на голову списка
Функция возвращает указатель на предпоследний элемент списка.
В случае его отсутствия - NULL.
*/
Node* get_prev_back(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
	{
		return NULL;
	}
	Node* curr = head;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	return curr;
}
/*
Аргументы: адрес указателя на голову списка.
Функция удаляет последний элемент списка.
Если список состоит из одного элемента - удалит его.
Возвращает 1 в случае успеха и 0 в противном случае.
*/
int pop_back(Node** head)
{
	if ((*head) == NULL)
	{
		return 0;
	}
	if (head == NULL)
	{
		return 0;
	}
	Node* new_back = get_prev_back((*head));
	if (new_back == NULL)
	{
		free(*head);
		(*head) = NULL;
		return 1;
	}
	free(new_back->next);
	new_back->next = NULL;
	return 1;
}
/*
Аргументы: указатель на голову списка.
Печатает содержимое списка.
*/
void print_list(Node* head)
{
	if (head == NULL)
	{
		printf("Empty!\n");
		return;
	}
	while (head != NULL)
	{
		printf("%d->", head->value);
		head = head->next;
	}
	printf("NULL\n");
}
/*
Аргументы: указатель на голову списка, место, значение
Функция добавляет элемент на n-ое место в списке.
Если n больше длины списка, то вставит в конец.
Возвращает 1 в случае успеха и 0 в противном случае.
*/
int push_back(Node* head, int n, int value)
{
	if (n < 0)
	{
		return 0;
	}
	int i = 0;
	Node* tmp = NULL;
	while (i < n && head->next != NULL)
	{
		head = head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		return 0;
	}
	tmp->value = value;
	if (head->next == NULL)
	{
		tmp->next = NULL;
	}
	else
	{
		tmp->next = head->next;
	}
	head->next = tmp;
	return 1;
}
/*
Аргументы: адрес указателя на голову списка, место.
Функция удаляет n-ый элемент списка.
Если n больше длины списка, удаляет последнй элемент.
Возвращает 1 в случае успеха и 0 в противном случае.
*/
int pop_N(Node** head, int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return (pop_head(head));
	}
	int i = 0;
	Node* prev = get_N((*head), n - 1);
	Node* curr = get_N((*head), n);
	prev->next = curr->next;
	free(curr);
	return 1;
}
/*
Аргументы: адрес указателя на голову списка.
Функция удаляет список.
Возвращает 1 в случае успеха и 0 в противном случае.
*/
int pop_list(Node** head)
{
	if (head == NULL)
	{
		return 0;
	}
	while ((*head) != NULL)
	{
		pop_head(head);
	}
	return 1;
}
/*
Аргументы: указатель на голову списка, искомое значение
Функция возвращает указатель на первый узел списка с 
искомым значением, если такого нет - NULL.
*/
Node* list_find(Node* head, int value)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node* curr = head;
	while (curr != NULL && curr->value != value)
	{
		curr = curr->next;
	}
	return curr;
}
/*
Аргументы: адрес указателя на голову списка, значение 
Функция удаляет все узлы с указанным значением.
Возвращает количество удаленных узлов.
*/
int remove_value(Node** head, int value)
{
	int count = 0;
	while ((*head) != NULL && (*head)->value == value)
	{
		pop_head(head);
		count++;
	}
	if ((*head) == NULL)
	{
		return count;
	}
	Node* prev = (*head);
	Node* curr = (*head)->next;
	if (curr == NULL)
	{
		return count;
	}
	while (curr != NULL)
	{
		if (curr->value == value)
		{
			Node* tmp = curr;
			prev->next = curr->next;
			curr = curr->next;
			free(tmp);
			count++;
		}
		else
		{
			curr = curr->next;
			prev = prev->next;
		}
	}
	return count;
}


