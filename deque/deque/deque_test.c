#include "deque_header.h"
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
/*
Библиотека для нахождения утечек памяти.
*/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int i = 0;
	deque* q = create_deque();
	for (i = 0; i < 100; i++)
	{
		push_back(q, i);
	}
	print_deque(q);
	print_reverse_deque(q);
	for (i = 100; i > 0; i--)
	{
		printf("%d\n", get_front(q));
	}
	print_deque(q);
	for (i = 0; i < 100; i++)
	{
		push_front(q, i);
	}
	print_deque(q);
	for (i = 100; i > 0; i--)
	{
		printf("%d\n", get_back(q));
	}
	print_deque(q);
	for (i = 0; i < 100; i++)
	{
		push_front(q, i);
	}
	//delete_deque(q);
	return 0;
}