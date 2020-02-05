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

//Adds item to front of queue
void addQueue(element *head, element *item) {
	
}
