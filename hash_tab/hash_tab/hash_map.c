#include <stdio.h>
#include <stdlib.h>
#include "header_hash.h"

ENTRY g_hash_map[N];

unsigned int hash(unsigned long long int key)
{
	return key % N;
}

void hash_map_init(void)
{

}

void hash_map_deinit(void)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (NULL != g_hash_map[i].function_name)
		{
			free(g_hash_map[i].function_name);
		}
	}
}

char* make_str(char* str)
{
	char* new_str = (char *)malloc(strlen(str) + 1);
	if (NULL == new_str)
	{
		exit(-1);
	}
	strcpy(new_str, str);
	return new_str;
}

unsigned int add(void* adress, char* function_name)
{
	unsigned int index = hash(adress);
	if (NULL != g_hash_map[index].adress)
	{
		printf("Collision!\n");
		return -1;
	}
	g_hash_map[index].adress = adress;
	g_hash_map[index].function_name = make_str(function_name);

	return index;
}

unsigned int del(void* adress)
{
	unsigned int index = hash(adress);
	if (g_hash_map[index].adress != NULL)
	{
		return -1;
	}
	g_hash_map[index].adress = NULL;
	if (NULL != g_hash_map[index].function_name)
	{
		free(g_hash_map[index].function_name);
	}
	g_hash_map[index].function_name = NULL;

	return index;
}

PENTRY find(void* adress)
{
	unsigned int index = hash(adress);
	if (g_hash_map[index].adress != NULL)
	{
		return &g_hash_map[index];
	}
	return NULL;
}