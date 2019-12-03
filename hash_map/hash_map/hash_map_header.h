#pragma once
/*
Hash-map
Author: Nikolai Nenashev
Moscow IPT 2019.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 256
#define UNINITIALIZED -102
#define OUT_OF_MEMORY -101
#define EMPTY_LIST_ERROR -100
typedef long long int T;

typedef struct Node_
{
	char* str;
	T value;
	struct Node_* next;
} Node;

typedef struct List_
{
	Node* head;
} list;

int hash1(char* str);

void init_table(list** hash_table);

void deinit_table(list** map);

void push_front(list* l, T value, char* str);

void del_node(list* l, Node* elem);

void insert_value(char* str, T value);

int delete_key(char* str);

Node* find_key(char* str);

void print_list(list* l);

void print_map(list** hash_map);

void delete_list(list* q);









