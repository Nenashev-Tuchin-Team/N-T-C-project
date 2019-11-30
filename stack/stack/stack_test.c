#include "stack_header.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i = 0;
	my_stack* stack = stack_create();

	for (i = 0; i < 100; i++)
	{
		stack_push(stack, i);
	}
	for (i = 0; i < 120; i++)
	{
		printf("get_top:\t %d\n", get_top(stack));
		printf("pop:\t %d\n", stack_pop(stack));
	}
	delete_stack(&stack);
	return 0;
}
