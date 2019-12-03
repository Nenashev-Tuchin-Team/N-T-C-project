#include "binary_tree_header.h"


tree* init_tree() 
{
	tree* tmp = (tree*)malloc(sizeof(tree));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->root = NULL;
	return tmp;
}

Node* create_node(T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->parent = parent;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->value = value;
	return tmp;
}

void insert(tree* t, T value)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (t->root == NULL)
	{
		t->root = create_node(value, NULL);
		return;
	}
	Node* tmp = NULL;
	tmp = t->root;
	while (tmp != NULL)
	{
		if (value >= tmp->value)
		{
			if (tmp->right != NULL)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = create_node(value, tmp);
				return;
			}
		}
		else
		{
			if (tmp->left != NULL)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = create_node(value, tmp);
				return;
			}
		}
	}
}


Node* find_value(Node* t, T value) 
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = t;
	while (tmp != NULL) 
	{
		if (tmp->value > value) 
		{
			tmp = tmp->left;
			continue;
		}
		else if (tmp->value < value)
		{
			tmp = tmp->right;
			continue;
		}
		else 
		{
			return tmp;
		}
	}
	return NULL;
}

Node* find_max(Node* t)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = t;
	while (tmp->right) 
	{
		tmp = tmp->right;
	}
	return tmp;
}

Node* find_min(Node* t)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = t;
	while (tmp->left) 
	{
		tmp = tmp->left;
	}
	return tmp;
}

void remove_node(Node* target) 
{
	if (target->left != NULL && target->right != NULL) 
	{
		Node* localMax = find_max(target->left);
		target->value = localMax->value;
		remove_node(localMax);
		return;
	}
	else if (target->left != NULL) 
	{
		if (target == target->parent->left) 
		{
			target->parent->left = target->left;
		}
		else 
		{
			target->parent->right = target->left;
		}
	}
	else if (target->right) 
	{
		if (target == target->parent->right)
		{
			target->parent->right = target->right;
		}
		else 
		{
			target->parent->left = target->right;
		}
	}
	else 
	{
		if (target == target->parent->left) 
		{
			target->parent->left = NULL;
		}
		else 
		{
			target->parent->right = NULL;
		}
	}
	free(target);
}


void delete_value(tree* t, T value)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* target = find_value(t->root, value);
	if (target != NULL)
	{
		remove_node(target);
		return;
	}
	return;
}


void printTree(Node* t, const char* dir, int level) 
{
	Node* tmp = t;
	if (tmp != NULL) 
	{
		printf("lvl %d %s = %d\n", level, dir, tmp->value);
		printTree(tmp->left, "left", level + 1);
		printTree(tmp->right, "right", level + 1);
	}
}