/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node * insertAtEveryKthNode(struct node *head, int K);
struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	struct node *tempptr;
	tempptr = (struct node *)malloc(sizeof(struct node));
	tempptr = head;
	
	if (head && (K>0)){
		do{
			int len = K;
			while (tempptr->next && (len>1)){
				len--;
				tempptr = tempptr->next;
			}
			if (tempptr->next && (len == 1)){
				struct node *new_node;
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->num = K;
				new_node->next = tempptr->next;
				tempptr->next = new_node;
				tempptr = tempptr->next;
			}
			else if (tempptr && (len == 1)){
				struct node *new_node;
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->num = K;
				new_node->next = tempptr->next;
				tempptr->next = new_node;
				break;
			}
			tempptr = tempptr->next;
		} while (tempptr);
		return head;
	}
	return NULL;
}
