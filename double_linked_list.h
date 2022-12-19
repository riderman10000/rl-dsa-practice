#include<stdio.h>
#include<stdlib.h>

struct doubleLinkedList{
	int data;
	struct doubleLinkedList *previous;
	struct doubleLinkedList *next;
};

void traverse_double_linked_list(struct doubleLinkedList *linkedlist);
void traverse_double_linked_list_reverse(struct doubleLinkedList *linkedlist);
struct doubleLinkedList *add_node_double_linked_list(struct doubleLinkedList *linkedlist, int data);

void traverse_double_linked_list(struct doubleLinkedList *linkedlist){
	while(linkedlist){
		printf("the data in the linked list %d\n", linkedlist->data);
		linkedlist = linkedlist->next;
	}
}

void traverse_double_linked_list_reverse(struct doubleLinkedList *linkedlist){
	while(linkedlist->next){
		linkedlist = linkedlist->next;
	}
	while(linkedlist){
		printf("the data in the linked list %d\n", linkedlist->data);
		linkedlist = linkedlist->previous;
	}	
}


struct doubleLinkedList *add_node_double_linked_list(struct doubleLinkedList *linkedlist, int data){
	struct doubleLinkedList *head;
	struct doubleLinkedList *newNode = (struct doubleLinkedList *)malloc(sizeof(struct doubleLinkedList));
	
	head = linkedlist;
	newNode->data = data;
	
	while(linkedlist->next){
		linkedlist = linkedlist->next;
	}
	
	linkedlist->next = newNode;
	newNode->previous = linkedlist;
	newNode->next = NULL;
	return head;
}
