/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head)
	{
		struct node *temp = NULL;
		struct node *current_node = head;
		struct node *nxt_node;
		while (current_node != NULL)
		{
			nxt_node = current_node->next;
			current_node->next = temp;
			temp = current_node;
			current_node = nxt_node;
		}
		return temp;
	}

	return NULL;
}
