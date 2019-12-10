#include "header_queue.h"
#include <stdio.h>
#include <stdlib.h>
#define M 1000000

int test1()
{
	int i = 0;
	queue* q = create_q();
	for (i = 0; i < 100; i++)
	{
		insert_queue(q, i);
	}
	delete_queue(q);
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	int i = 0;
	queue* q = create_q();
	for (i = 0; i < M; i++)
	{
		insert_queue(q, i);
	}
	for (i = 0; i < M; i++)
	{
		if (touch(q) != i)
		{
			delete_queue(q);
			printf("TEST_2 FAILED.\n");
			return 0;
		}
		if (get_queue(q) != i)
		{
			delete_queue(q);
			printf("TEST_2 FAILED.\n");
			return 0;
		}
	}
	delete_queue(q);
	printf("TEST_2 PASSED.\n");
	return 1;
}

int test3()
{
	int i = 0;
	queue* q = create_q();
	for (i = 0; i < M * 100; i++)
	{
		insert_queue(q, i);
	}
	return 0;
}

int test4()
{
	int i = 0;
	queue* q = create_q();
	for (i = 0; i < M; i++)
	{
		insert_queue(q, i);
	}
	for (i = 0; i < M; i++)
	{
		get_queue(q);
	}
	for (i = 0; i < M; i++)
	{
		touch(q);
	}
	return 0;
}