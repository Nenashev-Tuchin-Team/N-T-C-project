//test
#include "header_s-l_list.h"

int main()
{
	Node* head = NULL;
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
	printf("kekw\n");
	return 0;
}
