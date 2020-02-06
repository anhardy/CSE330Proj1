#include <stdlib.h>

//Queue item structure. Contains a payload and next and previous pointers
struct element {
	int payload = 0;
	element *next;
	element *prev;
};

//Creates a new item. Allocates space for the item and returns it.
element *newItem() {
	struct element *newItem = (struct element*)malloc(sizeof(struct element));

	return newItem;
}

//Initializes a queue
void initQueue(element *head) {
	head = NULL; //Head is set to NULL since queue is empty
}

//Add item to front of queue
void addQueue(element *head, element *item) {
	if (head == NULL) { //If queue empty
		item->next = item; //Loops to itself
		item->prev = item;
		head = item; //Items is new head
	}
	item->prev = head->prev; //Tail is previous of newly added element;
	head->prev->next = item; //New item is next element of tail;
	item->next = head; //Current head becomes next element of item;
	head = item; //Item becomes new head;
}

element *delQueue(element *head) {
	element *deletedItem = head;
	element *temp = head;
	if (head == NULL || head->next == NULL) { //Must have at at least two elements
		rotateQueue(head);
	}
	free(temp);
	return deletedItem;
}

//Move head pointer to next element
void rotateQueue(element *head) {
	head->next->prev = head->prev; //Next element's previous is now tail
	head->prev->next = head->next; //Tail's next element is next element of head
	head = head->next;
}
