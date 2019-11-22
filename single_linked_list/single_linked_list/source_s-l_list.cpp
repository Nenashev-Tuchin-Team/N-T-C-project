#include "header_s-l_list.h"

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
	if (list_find(head, 190) != NULL)
	{
		printf("Finded!\n");
	}
	print_list(head);
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
