#include <stdlib.h>
#include <stdio.h>
#define OUT_OF_MEMORY -100
#define EMPTY_QUEUE -101

typedef int T;

typedef struct Node_
{
	T value;
	struct Node_* next;
} Node;

typedef struct queue_
{
	Node* head;
	Node* back;
} queue;

queue* create_q()
{
	queue* q = NULL;
	q = (queue*)malloc(sizeof(queue));
	if (q == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	q->head = NULL;
	q->back = NULL;
	return q;
}

int is_empty(queue* q)
{
	if (q->head == NULL)
	{
		return 1;
	}
	return 0;
}

void insert_queue(queue* q, T value)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->value = value;
	tmp->next = NULL;
	if (q->head == NULL)
	{
		q->head = tmp;
		q->back = tmp;
		return;
	}
	q->back->next = tmp;
	q->back = tmp;
	return;
}

T get_queue(queue* q)
{
	if (q->head == NULL)
	{
		exit(EMPTY_QUEUE);
	}
	Node* tmp = q->head;
	T value = tmp->value;
	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->back = NULL;
	}
	free(tmp);
	return value;
}

void print_queue(queue* q)
{
	Node* curr = q->head;
	if (curr == NULL)
	{
		printf("Empty!\n");
	}
	while (curr != NULL)
	{
		printf("%d->", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}