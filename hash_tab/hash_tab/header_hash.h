#pragma once

#define FUNC_MAP
#define N 16

typedef struct _ENTRY
{
	void* adress;
	char* function_name;
} ENTRY, *PENTRY;

void hash_map_init(void);

void hash_map_deinit(void);

unsigned int add(void* adress, char* function_name);

unsigned int del(void* adress);

PENTRY find(void* adress);