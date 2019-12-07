#include "header_s-l_list.h"

Node* first_N_int(int N)
{
	if (N == 0)
	{
		return NULL;
	}
	Node* list = NULL;
	int i = 0;
	for (i = 1; i <= N; i++)
	{
		push_head(&list, i);
	}
	return list;
}