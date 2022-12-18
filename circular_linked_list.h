/*about circular linked list and operation*/

#include <stdio.h>
#include <stdlib.h>

void traverse_circular_linked_list(struct linkedList *linkedlist);
struct linkedList * add_node_to_circular_linked_list(struct linkedList * linkedlist, int data);
struct linkedList * delete_node_circular_linked_list(struct linkedList * linkedlist, int data);


void traverse_circular_linked_list(struct linkedList *linkedlist){
	struct linkedList *head;
	head = linkedlist;
	while(linkedlist->next != head){
		printf("the data in the linked list %d\n", linkedlist->data);
		linkedlist = linkedlist->next;
	}
	printf("the data in the linked list %d\n", linkedlist->data);
}

struct linkedList * add_node_to_circular_linked_list(struct linkedList * linkedlist, int data){
	struct linkedList *head;
	struct linkedList *newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
	newNode->data = data;
	head = linkedlist;
	while(linkedlist->next != head){
		linkedlist = linkedlist->next;
	}
	linkedlist->next = newNode;
	newNode->next = head;
	return head;
}

struct linkedList * delete_node_circular_linked_list(struct linkedList * linkedlist, int data){
	struct linkedList *head, *previousNodeAddress;
	head = linkedlist;
	previousNodeAddress = linkedlist;
	while(linkedlist->data != data && linkedlist->next != head){
		previousNodeAddress = linkedlist;
		linkedlist = linkedlist->next;
	}
	previousNodeAddress->next = linkedlist->next;
	return head;
}