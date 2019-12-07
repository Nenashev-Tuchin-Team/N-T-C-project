#include "header_s-l_list.h"
#include<stdlib.h>
#include<stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	START:
	printf("\nChoose test: 1 - 7, 8 - run all test.\n tests decription vide in header.\n 9 - finish program.\n");
	int n = 0;
	printf("You choise:");
	scanf_s("%d", &n);
	switch (n)
	{
		case 1: test1(); break;
		case 2: test2(); break;
		case 3: test3(); break;
		case 4: test4(); break;
		case 5: test5(); break;
		case 6: test6(); break;
		case 7: test7(); break;
		case 8:
			test1();
			test2();
			test3();
			test4();
			test5();
			test6();
			test7();
			break;
		case 9: return 0; break;
	}
	goto START;
	return 0;
}
