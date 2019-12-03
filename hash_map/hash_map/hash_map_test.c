#include "hash_map_header.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
extern list* hash_table[N];

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int i = 0;
	char str[] = { "adasdsadas" };
	init_table(hash_table);
	print_map(hash_table);
	for (i = 0; i < N;i++)
	{
		insert_value(str, i);
	}
	print_map(hash_table);
	deinit_table(hash_table);
	return 0;
}