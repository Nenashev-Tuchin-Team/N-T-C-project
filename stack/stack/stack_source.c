#include <stdlib.h>
typedef int T;
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102
#define INITIAL_SIZE 10
#define MULTIPLIER 2
#define IMPLODE_ERROR -103
typedef struct Stack_
{
	T* data;
	int size;
	int top;
} my_stack;

my_stack* stack_create()
{
	my_stack* out = NULL;
	out = (my_stack*)malloc(sizeof(my_stack));
	if (out == NULL)
	{
		exit(OUT_OF_MEMORY);
	}
	out->size = INITIAL_SIZE;
	out->data = (T*)malloc(out->size * sizeof(T));
	if (out->data == NULL)
	{
		free(out);
		exit(OUT_OF_MEMORY);
	}
	out->top = 0;
	return out;
}

void delete_stack(my_stack** s)
{
	free((*s)->data);
	free(*s);
	*s = NULL;
}

void resize(my_stack* s)
{
	s->size *= MULTIPLIER;
	T* tmp = NULL;
	tmp = (T*)realloc(s->data, s->size * sizeof(T));
	if (tmp == NULL)
	{
		delete_stack(&s);
		exit(STACK_OVERFLOW);
	}
	s->data = tmp;
	return;
}

void implode(my_stack* s)
{
	s->size = s->top;
	T* tmp = (T*)realloc(s->data, s->size * sizeof(T));
	if (tmp == NULL)
	{
		delete_stack(&s);
		exit(IMPLODE_ERROR);
	}
	s->data = tmp;
	return;
}

void stack_push(my_stack* s, T value)
{
	if (s->top >= s->size)
	{
		resize(s);
	}
	s->data[s->top] = value;
	s->top++;
}

T stack_pop(my_stack* s)
{
	if (s->top <= 0)
	{
		delete_stack(&s);
		exit(STACK_UNDERFLOW);
	}
	s->top--;
	return s->data[s->top];
}

T get_top(my_stack* s)
{
	if (s->top <= 0)
	{
		delete_stack(&s);
		exit(STACK_UNDERFLOW);
	}
	return s->data[s->top - 1];
}

