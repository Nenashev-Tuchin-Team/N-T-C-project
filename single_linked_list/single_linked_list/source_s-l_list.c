#include<stdlib.h>
#include<stdio.h>
typedef struct Node_
{
	int value;
	struct Node_* next;
} Node;

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

int push_back(Node** head, int value)
{
	Node* back = get_back((*head));
	if (back == NULL)
	{
		return push_head(head, value);
	}
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

int push_N(Node* head, int n, int value)
{
	if (n < 0)
	{
		return 0;
	}
	int i = 0;
	Node* tmp = NULL;
	while (i < n - 1 && head->next != NULL)
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
	Node* curr = NULL;
	curr = (*head)->next;
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



