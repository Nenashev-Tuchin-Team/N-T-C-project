#include "binary_tree_header.h"


void main() {
	tree* t = init_tree();
	insert(t, 10);
	insert(t, 12);
	insert(t, 8);
	insert(t, 9);
	insert(t, 7);
	insert(t, 3);
	insert(t, 4);
	printTree(t->root, "root", 0);
	printf("max = %d\n", find_max(t->root)->value);
	printf("min = %d\n", find_min(t->root)->value);
	delete_value(t, 4);
	printf("parent of 7 is %d\n", find_value(t->root, 7)->parent->value);
	printTree(t->root, "root", 0);
	delete_value(t, 8);
	printTree(t->root, "root", 0);
	printf("------------------\n");
	delete_value(t, 10);
	printTree(t->root, "root", 0);
}