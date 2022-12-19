/*about the linked list and operation: traverse, add and delete*/ 
#include<stdio.h>
#include <stdlib.h>

#include "double_linked_list.h"

void main(){
	struct doubleLinkedList *head = (struct doubleLinkedList *)malloc(sizeof(struct doubleLinkedList));
	head->data = 100;
	head->previous = NULL;
	head->next= NULL;
	head = add_node_double_linked_list(head, 111);
	head = add_node_double_linked_list(head, 222);
	head = add_node_double_linked_list(head, 333);
	head = add_node_double_linked_list(head, 444);
	traverse_double_linked_list(head);
	traverse_double_linked_list_reverse(head);
}