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

Node* create_node(tree* t, T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		deinit_tree(t, t->root);
		exit(OUT_OF_MEMORY);
	}
	tmp->parent = parent;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->value = value;
	return tmp;
}

int insert(tree* t, Node* root, T value)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
		return 0;
	}
	if (root == NULL)
	{
		t->root = create_node(t, value, NULL);
		return 1;
	}
	Node* tmp = root;
	if (value > tmp->value && tmp->right == NULL)
	{
		tmp->right = create_node(t, value, tmp);
		return 1;
	}
	if (value < tmp->value && tmp->left == NULL)
	{
		tmp->left = create_node(t, value, tmp);
		return 1;
	}
	if (value > tmp->value)
	{
		return insert(t, tmp->right, value);
	}
	if (value < tmp->value)
	{
		return insert(t, tmp->left, value);
	}
	return 0;
}

Node* find_value(Node* t, T value) 
{
	if (t == NULL)
	{
		return NULL;
	}
	if (value > t->value)
	{
		return find_value(t->right, value);
	}
	if (value < t->value)
	{
		return find_value(t->left, value);
	}
	else
	{
		return t;
	}
}

Node* find_max(tree* t, Node* root)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = root;
	while (tmp->right) 
	{
		tmp = tmp->right;
	}
	return tmp;
}

Node* find_min(tree* t, Node* root)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* tmp = root;
	while (tmp->left) 
	{
		tmp = tmp->left;
	}
	return tmp;
}

void remove_node(tree* t, Node* target)
{
	if (target->left != NULL && target->right != NULL) 
	{
		Node* localMax = find_max(t, target->left);
		target->value = localMax->value;
		remove_node(t, localMax);
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


int delete_value(tree* t, T value)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	Node* target = find_value(t->root, value);
	if (target != NULL)
	{
		remove_node(t, target);
		return 1;
	}
	return 0;
}

void print_pref(Node* t) 
{
	if (t != NULL)
	{
		printf("( %d ", t->value);
		print_pref(t->left);
		print_pref(t->right);
		printf(")");
	}
}

void print_post(Node* t)
{
	if (t != NULL)
	{
		printf("(");
		print_post(t->left);
		print_post(t->right);
		printf(" %d )", t->value);
	}
}

void deinit_tree(tree* t, Node* curr)
{
	if (t == NULL)
	{
		exit(UNINITIALIZED);
	}
	if (curr == NULL)
	{
		return;
	}
	deinit_tree(t, curr->left);
	deinit_tree(t, curr->right);
	if (curr->parent == NULL)
	{
		free(curr);
		free(t);
		return;
	}
	if (curr->left == NULL && curr->right == NULL)
	{
		if (curr == curr->parent->left)
		{
			curr->parent->left = NULL;
			free(curr);
			return;
		}
		else if (curr == curr->parent->right)
		{
			curr->parent->right = NULL;
			free(curr);
			return;
		}
	}
}
