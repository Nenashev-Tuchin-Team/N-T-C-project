
#include "header_queue.h"

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
	if (q == NULL || q->head == NULL)
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
		delete_queue(q);
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
		return;
	}
	while (curr != NULL)
	{
		printf("%d->", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

T touch(queue* q)
{
	if (q == NULL || q->head == NULL)
	{
		delete_queue(q);
		exit(EMPTY_QUEUE);
	}
	return q->head->value;
}

void delete_queue(queue* q)
{
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