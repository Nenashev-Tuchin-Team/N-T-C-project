#include "binary_tree_header.h"
#include<stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
START:
	printf("\nChoose test: 1 - 4, 8 - run all test.\n tests decription vide in header.\n 9 - finish program.\n");
	int n = 0;
	printf("You choise:");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: test1(); break;
	case 2: test2(); break;
	case 3: test3(); break;
	case 4: test4(); break;
	case 8:
		test1();
		test2();
		test3();
		test4();
		break;
	case 9: return 0; break;
	default: printf("Wrong input!\n"); break;
	}
	goto START;
	return 0;
}
