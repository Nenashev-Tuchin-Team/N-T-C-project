#include "hash_map_header.h"
#define M 100000
#include <stdlib.h>
#include <time.h>
#include <conio.h>
extern list * hash_table[N];

int test1()
{
	init_table(hash_table);
	int i = 0;
	int c = 0;
	for (i = 0; i < M;i++)
	{
		c = i % 256;
		insert_value(&((char)(c)), 5);
	}
	deinit_table(hash_table);
	for (i = 0; i < N; i++)
	{
		if (hash_table[i] != NULL)
		{
			printf("TEST_1 FAILED.\n");
			return 0;
		}
	}
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	init_table(hash_table);
	int i = 0;
	int c = 0;
	srand(time(NULL));
	for (i = 0; i < M;i++)
	{
		c = i % 256;
		insert_value(&((char)(c)), 5);
		if (find_key_and_value(&((char)(c)), 5) == NULL)
		{
			printf("TEST_2 FAILED.\n");
			return 0;
		}
	}
	for (i = 0; i < M;i++)
	{
		c = (char)(rand() % 256);
		insert_value(&((char)(c)), 5);
		if (find_key_and_value(&((char)(c)), 5) == NULL)
		{
			printf("TEST_2 FAILED.\n");
			return 0;
		}
	}
	deinit_table(hash_table);
	printf("TEST_2 PASSED.\n");
	return 1;
}

int test3()
{
	init_table(hash_table);
	int i = 0;
	int c = 0;
	srand(time(NULL));
	for (i = 0; i < M;i++)
	{
		c = i % 256;
		insert_value(&((char)(c)), 5);
	}
	for (i = 0; i < M; i++)
	{
		c = i % 256;
		delete_key(&((char)(c)));
		if (find_key(&((char)(c))) != NULL)
		{
			printf("TEST_3 FAILED.\n");
			return 0;
		}
	}
	for (i = 0; i < M;i++)
	{
		c = (char)(rand() % 256);
		insert_value(&((char)(c)), 5);
	}
	for (i = 0; i < M; i++)
	{
		c = (char)(rand() % 256);
		delete_key(&((char)(c)));
		if (find_key(&((char)(c))) != NULL)
		{
			printf("TEST_3 FAILED.\n");
			return 0;
		}
	}
	deinit_table(hash_table);
	printf("TEST_3 PASSED.\n");
	return 1;
}