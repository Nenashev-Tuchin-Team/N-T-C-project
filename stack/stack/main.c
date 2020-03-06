#include "stack_header.h"
#include<stdlib.h>
#include<stdio.h>
#include <conio.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{
	my_stack* stack = stack_create();
	int i = 0;
	char c = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '(')
		{
			stack_push(stack, 1);
		}
		if (c == '[')
		{
			stack_push(stack, 2);
		}
		if (c == '{')
		{
			stack_push(stack, 3);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if ((c == ')' || c == ']' || c == '}') && stack->top == 0)
			{
				stack_push(stack, 5);
				break;
			}
			if (c == ')' && stack->top != 0 && get_top(stack) == 1)
			{
				stack_pop(stack);
			}
			if (c == ']' && stack->top != 0 && get_top(stack) == 2)
			{
				stack_pop(stack);
			}
			if (c == '}' && stack->top != 0 && get_top(stack) == 3)
			{
				stack_pop(stack);
			}
		}
	}
	if (stack->top == 0)
	{
		printf("Pravilnaya\n");
	}
	else
	{
		printf("Nepravilnaya\n");
	}
	_getch();
	return 0;
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//START:
	//printf("\nChoose test: 1 - 5, 8 - run all test.\n tests decription vide in header.\n 9 - finish program.\n");
	//int n = 0;
	//printf("You choise:");
	//scanf_s("%d", &n);
	//switch (n)
	//{
	//case 1: test1(); break;
	//case 2: test2(); break;
	//case 3: test3(); break;
	//case 4: test4(); break;
	//case 5: test5(); break;
	//case 6: task(); break;
	//case 8:
	//	test1();
	//	test2();
	//	test3();
	//	//test4(); Ёти тесты рушат стэк и провер€ют его корректный выход при неправильной работе.
	//	//test5();
	//	break;
	//case 9: return 0; break;
	//default: printf("Wrong input!\n"); break;
	//}
	//goto START;
	//return 0;
	//< C:\Users\User\Documents\GitHub\N-T-C-project\stack\Debug\main.c
}