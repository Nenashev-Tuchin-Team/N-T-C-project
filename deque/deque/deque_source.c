
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
	if (q == NULL || q->head == NULL)
	{
		return 1;
	}
	return 0;
}

void push_back(deque* q, T value)
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

T get_front(deque* q)
{
	if (q->head == NULL)
	{
		exit(EMPTY_DEQUE);
	}
	Node* tmp = q->head;
	T value = tmp->value;
	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->back = NULL;
	}
	return value;
}

void print_deque(deque* q)
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

T touch_front(deque* q)
{
	if (q == NULL || q->head == NULL)
	{
		exit(EMPTY_DEQUE);
	}
	return q->head->value;
}

void delete_deque(deque* q)
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