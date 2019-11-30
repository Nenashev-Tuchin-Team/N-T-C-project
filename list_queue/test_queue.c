#include "header_queue.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i = 0;
	queue* q = create_q();
	for (i = 0; i < 100; i++)
	{
		insert_queue(q, i);
	}
	print_queue(q);
	for (i = 100; i > 0; i--)
	{
		printf("%d\n", get_queue(q));
	}
	return 0;
}