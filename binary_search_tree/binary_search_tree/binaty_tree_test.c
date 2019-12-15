#include "binary_tree_header.h"
#include <stdlib.h>
#include <time.h>
#define M 1000
#define N 1000

int test1()
{
	Node* t = init_tree(5);
	int i = 0;
	for (i = 0; i < M; i++)
	{
		insert(t, i);
	}
	deinit_tree(t);
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	Node* t = init_tree(rand() % 10000);
	int i = 0;
	int n = 0;
	srand(time(NULL));
	for (i = 0; i < M; i++)
	{
		n = rand() % 10000;
		insert(t, n);
		if (find_value(t, n) == NULL)
		{
			deinit_tree(t);
			printf("TEST_2 FAILED.\n");
			return 0;
		}
	}
	deinit_tree(t);
	printf("TEST_2 PASSED.\n");
	return 1;
}

int test3()
{
	srand(time(NULL));
	int root = 0;
	root = rand() % 10000;
	Node* t = init_tree(root);
	int i = 0;
	int n = 0;
	int A[N];
	for (i = 0; i < N; i++)
	{
		n = rand() % 10000;
		A[i] = n;
		insert(t, n);
		if (find_value(t, n) == NULL)
		{
			deinit_tree(t);
			printf("TEST_3 FAILED.\n");
			return 0;
		}
	}
	for (i = 0; i < N; i++)
	{
		delete_value(t, A[i]);
	}
	delete_value(t, root);
	printf("TEST_3 PASSED.\n");
	return 1;
}

int test4()
{
	printf("TEST_4: \n");
	Node* t = init_tree(5);
	insert(t, 8);
	insert(t, 2);
	insert(t, 6);
	insert(t, 9);
	insert(t, 10);
	insert(t, 7);
	insert(t, 4);
	insert(t, 1);
	insert(t, 3);
	insert(t, 0);
	printf("Post: \n");
	print_post(t);
	printf("\n");
	printf("Pref: \n");
	print_pref(t);
	printf("\n");
	deinit_tree(t);
	printf("END OF TEST_4\n ---------------\n");
}
