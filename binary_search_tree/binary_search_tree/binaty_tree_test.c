#include "binary_tree_header.h"


void main() {
	tree* t = init_tree();
	insert(t, t->root, 4);
	insert(t, t->root, 9);
	insert(t, t->root, 8);
	insert(t, t->root, 7);
	insert(t, t->root, 6);
	insert(t, t->root, 5);
	insert(t, t->root, 3);
	printTree(t->root);
	printf("\n");
	printf("max = %d\n", find_max(t->root)->value);
	printf("min = %d\n", find_min(t->root)->value);
	delete_value(t, 4);
	//printf("parent of 7 is %d\n", find_value(t->root, 7)->parent->value);
	printTree(t->root);
	printf("\n");
	delete_value(t, 8);
	printTree(t->root);
	printf("\n");
	printf("------------------\n");
	//delete_value(t, 10);
	printTree(t->root);
}