/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *current = head;
	int len = 1;
	if (head)
	{
		//using fast slow pointer strategy of mergesort...to find out the middle elemnt
		struct node *fast_ptr;
		struct node *slow_ptr;
		fast_ptr = current->next;
		slow_ptr = current;
		while (fast_ptr != NULL)
		{
			fast_ptr = fast_ptr->next;
			len++;
			if (fast_ptr!= NULL)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
				len++;
			}
		}
		if (len % 2 == 0)
		{
			return ((slow_ptr->num) + (slow_ptr->next->num)) / 2;
		}
		else
		{
			return slow_ptr->num;
		}
	}
	return -1;
}
