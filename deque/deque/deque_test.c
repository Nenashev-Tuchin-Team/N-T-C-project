#include "deque_header.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i = 0;
	deque* q = create_deque();
	for (i = 0; i < 100; i++)
	{
		push_back(q, i);
	}
	print_deque(q);
	for (i = 100; i > 0; i--)
	{
		printf("%d\n", get_front(q));
	}
	print_deque(q);
	delete_deque(q);
	return 0;
}