#include "header_s-l_list.h"
#define N 10000

int test1()
{
	Node* head = NULL;
	head = create_list(0);
	pop_list(&head);
	printf("TEST_1 PASSED.\n");
	return 1;
}

int test2()
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		push_head(&head, i);
	}
	for (i = 0; i < N * 2; i++)
	{
		count += pop_head(&head);
	}
	if (count == N)
	{
		printf("TEST_2 PASSED.\n");
		pop_list(&head);
		return 1;
	}
	pop_list(&head);
	printf("TEST_2 FAILED.\n");
	return 0;
}
int test3()
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		push_back(&head, i);
	}
	for (i = 0; i < N * 2; i++)
	{
		count += pop_back(&head);
	}
	if (count == N)
	{
		printf("TEST_3 PASSED.\n");
		pop_list(&head);
		return 1;
	}
	pop_list(&head);
	printf("TEST_3 FAILED.\n");
	return 0;
}

	//if (list_find(head, 190) != NULL)
	//{
	//	printf("Finded!\n");
	//}
	//if (list_find(head, 123213) == NULL)
	//{
	//	printf("Not Finded!\n");
	//}
	//printf("190: %d\n", remove_value(&head, 190));
	//printf("20: %d\n", remove_value(&head, 20));
	//printf("6: %d\n", remove_value(&head, 6));
	//printf("8: %d\n", remove_value(&head, 8));
	//pop_back(&head);
	//pop_back(&head);
	//pop_back(&head);
	//print_list(head);
	//pop_back(&head);
	//print_list(head);
	//push_head(&head, 6);
	//push_head(&head, 7);
	//push_head(&head, 8);
	//print_list(head);
	//pop_list(&head);
	//print_list(head);
	//Node* list2 = first_N_int(100);
	//print_list(list2);
	//pop_list(&list2);