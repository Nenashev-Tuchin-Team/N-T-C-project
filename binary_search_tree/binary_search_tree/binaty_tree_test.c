#include "binary_tree_header.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tree* t = init_tree();
	insert(t, t->root, 4);
	insert(t, t->root, 9);
	insert(t, t->root, 5);
	insert(t, t->root, 6);
	insert(t, t->root, 3);
	insert(t, t->root, 1);
	insert(t, t->root, 7);
	insert(t, t->root, 7);
	int i = 0;
	//for (i = 0; i < 100; i++)
	//{
	//	insert(t, t->root, i);
	//}
	print_pref(t->root);
	printf("\n");
	printf("-----------------------\n");
	print_post(t->root);
	//printf("\n");
	//printf("max = %d\n", find_max(t, t->root)->value);
	//printf("min = %d\n", find_min(t, t->root)->value);
	//delete_value(t, 4);
	printf("parent of 7 is %d\n", find_value(t->root, 7)->parent->value);
	//printf("parent of 120 is %d\n", find_value(t->root, 120)->parent->value);
	////print_pref(t->root);
	//printf("\n");
	//delete_value(t, 8);
	//print_pref(t->root);
	//printf("\n");
	//printf("------------------\n");
	//delete_value(t, 10);
	//print_pref(t->root);
	deinit_tree(t, t->root);
}