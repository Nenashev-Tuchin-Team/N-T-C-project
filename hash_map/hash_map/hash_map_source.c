#include "hash_map_header.h"
list* hash_table[N];

int hash1(char* str)
{
	unsigned int key = 0;
	while (*str)
		key ^= *str++;
	return key % N;
}

void init_table(list** hash_table)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		hash_table[i] = (list*)malloc(sizeof(list));
		if (hash_table[i] == NULL)
		{
			exit(OUT_OF_MEMORY);
		}
		hash_table[i]->head = NULL;
	}
	return;
}

void deinit_table(list** map)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		delete_list(hash_table[i]);
		hash_table[i] = NULL;
	}
	return;
}

void delete_list(list* q)
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
		free(tmp->str);
		free(tmp);
	}
	free(q);
	return;
}

void push_front(list* l, T value, char* str)
{
	if (l == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->next = NULL;
	tmp->value = value;
	tmp->str = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (tmp->str == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	strcpy_s(tmp->str, (sizeof(char) * strlen(str) + 1), str);
	if (l->head == NULL)
	{
		l->head = tmp;
		return;
	}
	tmp->next = l->head;
	l->head = tmp;
	return;
}

void del_node(list* l, Node* elem)
{
	if (l == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (l->head == NULL)
	{
		exit(EMPTY_LIST_ERROR);
	}
	if (l->head == elem)
	{
		Node* tmp = l->head;
		l->head = l->head->next;
		free(tmp->str);
		free(tmp);
		return;
	}
	Node* prev = l->head;
	while (prev->next != elem)
	{
		prev = prev->next;
	}
	prev->next = elem->next;
	free(elem);
	return;
}

void insert_value(char* str, T value)
{
	unsigned int key = hash1(str);
	push_front(hash_table[key], value, str);
}

int delete_key(char* str)
{
	if (find_key(str) != NULL)
	{
		del_node(hash_table[hash1(str)], find_key(str));
		return 1;
	}
	return 0;
}

Node* find_key(char* str)
{
	unsigned int key = hash1(str);
	Node* curr = hash_table[key]->head;
	while (curr != NULL)
	{
		if (strcmp(curr->str, str) == 0)
		{
			return curr;
		}
	}
	return NULL;
}

void print_list(list* l)
{
	if (l == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* curr = l->head;
	if (curr == NULL)
	{
		printf("Empty!\n");
		return;
	}
	while (curr != NULL)
	{
		printf("[%s, %llu]->", curr->str, curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

void print_map(list** hash_map)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("Bucket [%d]: \n", i);
		print_list(hash_map[i]);
	}
	return;
}
