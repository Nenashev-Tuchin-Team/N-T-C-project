#include "header_s-l_list.h"
#include <time.h>
#include <conio.h>
#define N 10000
#define M 100

int test1()
{
	Node* head = NULL;
	head = create_list(0);
	int i = 0;
	for (i = 0; i < M; i++)
	{
		push_head(&head, i);
	}
	pop_list(&head);
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		push_head(&head, i);
	}
	for (i = 0; i < N * 2; i++)
	{
		count += pop_head(&head);
	}
	if (count == N)
	{
		printf("TEST_2 PASSED.\n");
		pop_list(&head);
		return 1;
	}
	pop_list(&head);
	printf("TEST_2 FAILED.\n");
	return 0;
}
int test3()
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		push_back(&head, i);
	}
	for (i = 0; i < N * 2; i++)
	{
		count += pop_back(&head);
	}
	if (count == N)
	{
		printf("TEST_3 PASSED.\n");
		pop_list(&head);
		return 1;
	}
	pop_list(&head);
	printf("TEST_3 FAILED.\n");
	return 0;
}

int test4()
{
	Node* head = NULL;
	int i = 0;
	srand(time(NULL));
	int count = 0;
	count += push_N(&head, 0, 321);
	for (i = 1; i < M; i++)
	{
		count += push_N(&head, rand() % 500, rand() % 100);
	}
	if (count != M)
	{
		printf("TEST_4 FAILED.\n");
		return 0;
	}
	for (i = 0; i < M; i++)
	{
		count -= pop_N(&head, rand() % M);
	}
	if (count != 0)
	{
		printf("TEST_4 FAILED.\n");
		return 0;
	}
	pop_list(&head);
	printf("TEST_4 PASSED.\n");
	return 1;
	pop_list(&head);
}

int test5()
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	for (i = 0; i < M; i++)
	{
		push_head(&head, i);
	}
	for (i = 0; i < M; i++)
	{
		if (list_find(head, i)->value != i)
		{
			printf("TEST_5 FAILED.\n");
			return 0;
		}
	}
	if (list_find(head, M) != NULL)
	{
		printf("TEST_5 FAILED.\n");
		return 0;
	}
	pop_list(&head);
	printf("TEST_5 PASSED.\n");
	return 1;
}

int test6()
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		push_head(&head, M);
	}
	for (i = 0; i < N; i++)
	{
		count += remove_value(&head, M);
	}
	if (count != N)
	{
		printf("TEST_6 FAILED.\n");
		return 0;
	}
	pop_list(&head);
	printf("TEST_6 PASSED.\n");
	return 1;
}

int test7()
{
	Node* head = NULL;
	head = first_N_int(0);
	if (head != NULL)
	{
		printf("TEST_7 FAILED.\n");
		return 0;
	}
	int i = 0;
	int n = 0;
	srand(time(NULL));
	for (i = 0; i < M; i++)
	{
		n = rand() % N;
		head = first_N_int(n);
		if (n == 0 && head != NULL)
		{
			pop_list(&head);
			printf("TEST_7 FAILED.\n");
			return 0;
		}
		else
		{
			if (head != NULL && head->value != n)
			{
				pop_list(&head);
				printf("TEST_7 FAILED.\n");
				return 0;
			}
		}
		pop_list(&head);
	}
	pop_list(&head);
	printf("TEST_7 PASSED.\n");
	return 1;
}