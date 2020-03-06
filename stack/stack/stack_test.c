#include "stack_header.h"
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#define M 100000
#define MM 1000000000

int test1()
{
	my_stack* stack = stack_create();
	int i = 0;
	for (i = 0; i < M; i++)
	{
		stack_push(stack, i);
	}
	delete_stack(&stack);
	if (stack != NULL)
	{
		printf("TEST_1 FAILED.\n");
		return 0;
	}
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	my_stack* stack = stack_create();
	int i = 0;
	for (i = 0; i < M; i++)
	{
		stack_push(stack, i);
	}
	for (i = M - 1; i >= 0; i--)
	{
		if (stack_pop(stack) != i)
		{
			printf("TEST_2 FAILED.\n");
			return 0;
		}
	}
	delete_stack(&stack);
	printf("TEST_2 PASSED.\n");
	return 1;
}

int test4()
{
	my_stack* stack = stack_create();
	int i = 0;
	for (i = 0; i < MM; i++)
	{
		stack_push(stack, i);
	}
	delete_stack(&stack);
	return 1;
}

int test3()
{
	my_stack* stack = stack_create();
	int i = 0;
	for (i = 0; i < M; i++)
	{
		stack_push(stack, i);
	}
	for (i = M - 1; i >= 50; i--)
	{
		if (stack_pop(stack) != i)
		{
			printf("TEST_3 FAILED.\n");
			return 0;
		}
	}
	implode(stack);
	delete_stack(&stack);
	printf("TEST_3 PASSED.\n");
	return 1;
}

int test5()
{
	my_stack* stack = stack_create();
	int i = 0;
	for (i = 0; i < M; i++)
	{
		stack_push(stack, i);
	}
	for (i = 0; i < M + M; i++)
	{
		stack_pop(stack);
	}
	return 1;
}
