#pragma once
/*
Binary tree
Author: Nikolai Nenashev
Moscow IPT, 2019.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define OUT_OF_MEMORY -100
#define EMPTY_TREE -101
#define UNINITIALIZED -102

typedef int T;

typedef struct Node_
{
	T value;
	struct Node_* right;
	struct Node_* left;
	struct Node_* parent;
} Node;

typedef struct Tree_
{
	Node* root;
} tree;

tree* init_tree();

Node* create_node(T value, Node* parent);

void insert(tree* t, T value);

Node* find_value(Node* t, T value);

Node* find_max(Node* t);

Node* find_min(Node* t);

void remove_node(Node* target);

void delete_value(tree* t, T value);

void printTree(Node* t, const char* dir, int level);