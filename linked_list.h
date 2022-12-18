#include <stdio.h>
#include <stdlib.h>

struct linkedList{
	int data;
	struct linkedList *next;
};

void traverse_linked_list(struct linkedList * linkedlist);
void add_node(struct linkedList * linkedlist, int data);
void add_node_at_beginning(struct linkedList * linkedlist, int data);
void add_node_after(struct linkedList * linkedlist, int node_data, int node_data_to_add);
void delete_node(struct linkedList * linkedlist, int data);

void traverse_linked_list(struct linkedList * linkedlist){
	while(linkedlist){
		printf("the data in the linked list %d\n", linkedlist->data);
		linkedlist = linkedlist->next;
	}
}

void add_node(struct linkedList * linkedlist, int data){
	// store the data in the heap
	struct linkedList * newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
	newNode->data = data;
	newNode->next = NULL;
	while(linkedlist->next){ //traversing to last node to add the new node at the end
		linkedlist = linkedlist->next;
		// printf("address of next %p \n", linkedlist);
	}
	linkedlist->next = newNode;
	// printf("the data in the linked list %d\n", linkedlist->data);
}

void add_node_at_beginning(struct linkedList * linkedlist, int data){
	struct linkedList * newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
	newNode->data = linkedlist->data;
	linkedlist->data = data;
	newNode->next = linkedlist->next;
	linkedlist->next = newNode;
}


void delete_node(struct linkedList * linkedlist, int data){
	// break the chain and remove the address of chain 
	struct linkedList *previousNodeAddress;
	previousNodeAddress = linkedlist;
	while(linkedlist -> data != data){
		previousNodeAddress  = linkedlist;
		linkedlist = linkedlist->next;
	}
	previousNodeAddress->next = linkedlist->next;
}