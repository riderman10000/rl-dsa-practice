#include <stdio.h>
#include <stdlib.h>

struct linkedList{
	int data;
	struct linkedList *next;
};

void traverse_linked_list(struct linkedList * linkedlist);
void add_node(struct linkedList * linkedlist, int data);

void traverse_linked_list(struct linkedList * linkedlist){
	while(linkedlist){
		printf("the data in the linked list %d\n", linkedlist->data);
		linkedlist = linkedlist->next;
	}
}

void add_node(struct linkedList * linkedlist, int data){
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