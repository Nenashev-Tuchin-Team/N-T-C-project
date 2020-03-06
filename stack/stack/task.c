//#include "stack_header.h"
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//int task()
//{
//	my_stack* stack = stack_create();
//	int i = 0;
//	char c = 0;
//	while ((c = getchar()) != EOF)
//	{
//		if (c == '(')
//		{
//			stack_push(stack, 1);
//		}
//		else if (c == ')')
//		{
//			if (stack->top < 0)
//			{
//				printf("Nepravilnaya\n");
//				return 0;
//			}
//			else
//			{
//				stack_pop(stack);
//			}
//		}
//		else
//			continue;
//	}
//	if (stack->top == 0)
//	{
//		printf("Pravilnaya\n");
//		return 1;
//	}
//	return 0;
//}