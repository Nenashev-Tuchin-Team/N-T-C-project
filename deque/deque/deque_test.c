#include "deque_header.h"
#define M 1000000

int test1()
{
	deque* q = create_deque();
	int i = 0;
	for (i = 0; i < M; i++)
	{
		push_back(q, i);
	}
	delete_deque(q);
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	deque* q = create_deque();
	int i = 0;
	int n = 0;
	for (i = 0; i < M; i++)
	{
		push_back(q, i);
	}
	if (q->back == NULL || q->head == NULL)
	{
		printf("TEST_2 FAILED.\n");
		delete_deque(q);
		return 0;
	}
	for (i = M - 1; i >= 0; i--)
	{
		if (get_back(q) != i)
		{
			printf("TEST_2 FAILED.\n");
			delete_deque(q);
			return 0;
		}
	}
	delete_deque(q);
	printf("TEST_2 PASSED.\n");
	return 1;
}

int test3()
{
	deque* q = create_deque();
	int i = 0;
	int n = 0;
	for (i = 0; i < M; i++)
	{
		push_front(q, i);
	}
	if (q->back == NULL || q->head == NULL)
	{
		printf("TEST_3 FAILED.\n");
		delete_deque(q);
		return 0;
	}
	for (i = M - 1; i >= 0; i--)
	{
		if (get_front(q) != i)
		{
			printf("TEST_3 FAILED.\n");
			delete_deque(q);
			return 0;
		}
	}
	delete_deque(q);
	printf("TEST_3 PASSED.\n");
	return 1;
}
int test4()
{
	deque* q = create_deque();
	int i = 0;
	int n = 0;
	for (i = 0; i < M; i++)
	{
		push_front(q, i);
	}
	if (q->back == NULL || q->head == NULL)
	{
		printf("TEST_4 FAILED.\n");
		delete_deque(q);
		return 0;
	}
	for (i = M - 1; i >= 0; i--)
	{
		if (touch_front(q) != i)
		{
			printf("TEST_4 FAILED.\n");
			delete_deque(q);
			return 0;
		}
		get_front(q);
	}
	delete_deque(q);
	printf("TEST_4 PASSED.\n");
	return 1;
}

int test5()
{
	deque* q = create_deque();
	int i = 0;
	int n = 0;
	for (i = 0; i < M; i++)
	{
		push_back(q, i);
	}
	if (q->back == NULL || q->head == NULL)
	{
		printf("TEST_2 FAILED.\n");
		delete_deque(q);
		return 0;
	}
	for (i = M - 1; i >= 0; i--)
	{
		if (touch_back(q) != i)
		{
			printf("TEST_5 FAILED.\n");
			delete_deque(q);
			return 0;
		}
		get_back(q);
	}
	delete_deque(q);
	printf("TEST_5 PASSED.\n");
	return 1;
}