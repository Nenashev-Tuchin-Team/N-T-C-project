#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "deque_header.h"

deque* create_deque()
{
	deque* q = NULL;
	q = (deque*)malloc(sizeof(deque));
	if (q == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	q->head = NULL;
	q->back = NULL;
	return q;
}

int is_empty(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (q->head == NULL)
	{
		return 1;
	}
	return 0;
}

void push_back(deque* q, T value)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (q->head == NULL)
	{
		q->head = tmp;
		q->back = tmp;
		return;
	}
	q->back->next = tmp;
	tmp->prev = q->back;
	q->back = tmp;
	return;
}

T get_front(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (q->head == NULL)
	{
		exit(EMPTY_DEQUE);
	}
	Node* tmp = q->head;
	T value = tmp->value;
	q->head = q->head->next;
	free(tmp);
	if (q->head != NULL)
	{
		q->head->prev = NULL;
		return value;
	}
	q->back = NULL;
	return value;
}

void print_deque(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* curr = q->head;
	if (curr == NULL)
	{
		printf("Empty!\n");
		return;
	}
	while (curr != NULL)
	{
		printf("%d->", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

void print_reverse_deque(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* curr = q->back;
	if (curr == NULL)
	{
		printf("Empty!\n");
		return;
	}
	while (curr != NULL)
	{
		printf("%d<-", curr->value);
		curr = curr->prev;
	}
	printf("NULL\n");
}

T touch_front(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (q->head == NULL)
	{
		exit(EMPTY_DEQUE);
	}
	return q->head->value;
}

void delete_deque(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* curr = q->head;
	Node* tmp = NULL;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(q);
}

void push_front(deque* q, T value)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->value = value;
	if (q->head == NULL)
	{
		q->head = tmp;
		q->back = tmp;
		return;
	}
	q->head->prev = tmp;
	tmp->next = q->head;
	q->head = tmp;
	return;
}

T get_back(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (q->head == NULL)
	{
		exit(EMPTY_DEQUE);
	}
	Node* tmp = q->back;
	T value = q->back->value;
	if (q->back == q->head)
	{
		return get_front(q);
	}
	q->back->prev->next = NULL;
	q->back = q->back->prev;
	free(tmp);
	return value;
	return 0;
}
	
T touch_back(deque* q)
{
	if (q == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (q->head == NULL)
	{
		exit(EMPTY_DEQUE);
	}
	return q->back->value;
}

