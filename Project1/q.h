#include <stdlib.h>
#include <stdio.h>

//Queue item structure. Contains a payload and next and previous pointers
typedef struct element {
	int payload;
	struct element *next;
	struct element *prev;
} element;

//Creates a new item. Allocates space for the item and returns it.
element* newItem() {
	struct element *newItem = (element*)malloc(sizeof(element));
	newItem->next = NULL;
	newItem->prev = NULL;
	//newItem->payload = 0;
	return newItem;
}

//Initializes a queue
void initQueue(element **head) {
	*head = NULL; //Head is set to NULL since queue is empty
}

//Add item to front of queue
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
		*head = item; //Item becomes new head;
	}
}

//Move head pointer to next element
void rotateQueue(element **head) {
	element *tempHead = head;
	tempHead->next->prev = tempHead->prev; //Next element's previous is now tail
	tempHead->prev->next = tempHead->next; //Tail's next element is next element of head
	head = tempHead->next;
}

element* delQueue(element *head) {
	element *deletedItem = head;
	element *temp = head;
	if (head == NULL || head->next == NULL) { //Must have at at least two elements
		rotateQueue(head);
	}
	free(temp);
	return deletedItem;
}


