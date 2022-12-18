/*about the linked list and operation: traverse, add and delete*/ 
#include<stdio.h>

#include <stdlib.h>

#include "my_array.h"
#include "sorting_algorithm.h"
#include "search_algorithm.h"
#include "linked_list.h"
#include "circular_linked_list.h"


void main(){
	struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));
	head->next = head;
	head->data = 100; 
	head = add_node_to_circular_linked_list(head, 123);
	head = add_node_to_circular_linked_list(head, 111);
	head = add_node_to_circular_linked_list(head, 222);
	head = add_node_to_circular_linked_list(head, 333);
	traverse_circular_linked_list(head);
	head = delete_node_circular_linked_list(head, 222);
	traverse_circular_linked_list(head);

}