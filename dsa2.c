#include<stdio.h>

#include <stdlib.h>

#include "my_array.h"
#include "sorting_algorithm.h"
#include "search_algorithm.h"
#include "linked_list.h"

void main(){
	struct linkedList head;
	struct linkedList node1, node2, node3;
	head.data = 12;
	head.next = &node1;
	node1.data = 122;
	node1.next = &node2;
	node2.data = 144;
	node2.next = &node3;
	node3.data = 112;
	node3.next = NULL;
	traverse_linked_list(&head);
	add_node(&head, 999);
	traverse_linked_list(&head);
}