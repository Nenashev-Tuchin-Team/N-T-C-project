#include "binary_tree_header.h"


Node* init_tree(T value)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	tmp->value = value;
	return tmp;
}

Node* create_node(Node* root, T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		deinit_tree(root);
		exit(OUT_OF_MEMORY);
	}
	tmp->parent = parent;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->value = value;
	return tmp;
}

int insert(Node* root, T value)
{
	Node* tmp = root;
	if (value > tmp->value && tmp->right == NULL)
	{
		tmp->right = create_node(root, value, tmp);
		return 1;
	}
	if (value < tmp->value && tmp->left == NULL)
	{
		tmp->left = create_node(root, value, tmp);
		return 1;
	}
	if (value > tmp->value)
	{
		return insert(tmp->right, value);
	}
	if (value < tmp->value)
	{
		return insert(tmp->left, value);
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

Node* find_max(Node* root)
{

	Node* tmp = root;
	while (tmp->right) 
	{
		tmp = tmp->right;
	}
	return tmp;
}

Node* find_min(Node* root)
{
	Node* tmp = root;
	while (tmp->left) 
	{
		tmp = tmp->left;
	}
	return tmp;
}

Node* delete_value(Node* root, T value)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root != NULL && root->value > value) 
	{
		root->left = delete_value(root->left, value);
		return root;
	}
	else if (root->value < value) 
	{
		root->right = delete_value(root->right, value);
		return root;
	}
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			Node* locMax = find_max(root->left);
			root->value = locMax->value;
			root->left = delete_value(root->left, locMax->value);
			return root;
		}
		else if (root->left != NULL) 
		{
			Node* tmp = root->left;
			free(root);
			return tmp;
		}
		else if (root->right != NULL)
		{
			Node* tmp = root->right;
			free(root);
			return tmp;
		}
		else
		{
			free(root);
			return NULL;
		}

	}
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

void deinit_tree(Node* curr)
{
	if (curr == NULL)
	{
		return;
	}
	if (curr != NULL)
	{
		deinit_tree(curr->left);
		deinit_tree(curr->right);
	}
	if (curr->parent == NULL)
	{
		free(curr);
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
