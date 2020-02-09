#include <stdlib.h>
#include <stdio.h>

/*
Defines structure for elements within queue
*/
typedef struct element {
	int payload;
	struct element *next;
	struct element *prev;
} element;

/*
Creates a new item. Allocates space for item and sets default
values
*/
element* newItem() {
	struct element *newItem = (element*)malloc(sizeof(element));
	newItem->next = NULL;
	newItem->prev = NULL;
	return newItem;
}
/*
Initializes queue. head is NULL when first initalizing.
*/
void initQueue(element **head) {
	*head = NULL; //Head is set to NULL since queue is empty
}

/*
Takes in a pointer to the front of the queue and a new element.
Determins whether or not the queue is empty and adds items accordingly.
*/
void addQueue(element **head, element *item) {
	if (*head == NULL) { //If queue empty
		item->next = item; //Loops to itself
		item->prev = item;
		*head = item; //Items is new head
	}
	else {
		element *tempHead = *head;
		item->prev = tempHead->prev; //Tail is previous of newly added element;
		tempHead->prev->next = item; //New item is next element of tail;
		tempHead->prev = item; //Previous of original head is new item
		item->next = *head; //Current head becomes next element of item;
	}
}

/*
Moves head pointer to the next element
*/
void rotateQueue(element **head) {
	element *tempHead = *head;
	tempHead->next->prev = tempHead->prev; //Next element's previous is now tail
	tempHead->prev->next = tempHead->next; //Tail's next element is next element of head
	*head = tempHead->next;
}

/*
Deletes the element at the head of the queue and calls rotateQueue()
if there are two or more elements.
*/
element* delQueue(element **head) {
	//element *deletedItem = *head;
	element *tempQueue = *head;
	element *tempHead = *head;
	if (tempHead != NULL && tempHead->next != NULL) { //Must have at at least two elements
		rotateQueue(&tempQueue);
		*head = tempQueue;
	}
	else {
		*head = NULL;
	}
	return tempHead;
}


