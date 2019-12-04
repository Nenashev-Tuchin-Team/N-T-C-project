#include "hash_map_header.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
extern list* hash_table[N];

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int i = 0;
	char str[256] = { "adasdsadas" };
	init_table(hash_table);
	print_map(hash_table);
	for (i = 0; i < N;i++)
	{
		insert_value(&((char)i), 5);
	}
	for (i = 0; i < N;i++)
	{
		insert_value(&((char)i), 7);
	}
	for (i = 0; i < N;i++)
	{
		insert_value(str, 15);
	}
	print_map(hash_table);
	if (find_key(str) != NULL)
	{
		printf("Finded!\n");
	}
	else
	{
		printf("Not Finded!\n");
	}
	if (find_key("sds") != NULL)
	{
		printf("Finded!\n");
	}
	else
	{
		printf("Not Finded!\n");
	}
	if (find_key_and_value("a", 32) != NULL)
	{
		printf("**Finded!\n");
	}
	else
	{
		printf("**Not Finded!\n");
	}
	deinit_table(hash_table);
	return 0;
}