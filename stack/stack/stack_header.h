#pragma once
/*
Динамически растущий стек на массиве
Author: Nenashev Nikolai
Noscow IPT 2019.
*/
#include <stdlib.h>
typedef int T;
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102
#define INITIAL_SIZE 10
#define MULTIPLIER 2 
typedef struct Stack_
{
	T* data;
	int size;
	int top;
} my_stack;

my_stack* stack_create();

void delete_stack(my_stack** s);

void resize(my_stack* s);

void implode(my_stack* s);

void stack_push(my_stack* s, T value);

T stack_pop(my_stack* s);

T get_top(my_stack* s);

