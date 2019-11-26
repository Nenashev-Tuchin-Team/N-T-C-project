#include "header_s-l_list.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
	Node* head = NULL;
	head = create_list(0);
	print_list(head);
	push_head(&head, 5);
	print_list(head);
	pop_head(&head);
	print_list(head);
	push_head(&head, 6);
	push_head(&head, 7);
	push_head(&head, 8);
	print_list(head);
	push_back(head, 190);
	print_list(head);
	push_N(head, 2, 2132);
	print_list(head);
	pop_N(&head, 2);
	print_list(head);
	if (list_find(head, 190) != NULL)
	{
		printf("Finded!\n");
	}
	if (list_find(head, 123213) == NULL)
	{
		printf("Not Finded!\n");
	}
	printf("190: %d\n", remove_value(&head, 190));
	printf("20: %d\n", remove_value(&head, 20));
	printf("6: %d\n", remove_value(&head, 6));
	printf("8: %d\n", remove_value(&head, 8));
	pop_back(&head);
	pop_back(&head);
	pop_back(&head);
	print_list(head);
	pop_back(&head);
	print_list(head);
	push_head(&head, 6);
	push_head(&head, 7);
	push_head(&head, 8);
	print_list(head);
	pop_list(&head);
	print_list(head);
	return 0;
}
