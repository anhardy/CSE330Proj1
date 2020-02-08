#include "q.h"

void printQueue(element **head) {
	element *tempHead = *head;
	element *tempQueue = *head;
	if (tempQueue != NULL) {
		printf("Element Value: %d\n", tempQueue->payload); //Print first value
		tempQueue = tempQueue->next; //Move to second element
	}

	while (tempQueue != tempHead) { //Print remaining elements until loops back to head
		printf("Element Value: %d\n", tempQueue->payload); 
		tempQueue = tempQueue->next;
	}
	printf("\n"); 
}


int main() {
	element *q1 = newItem();
	initQueue(&q1);
	element *item1 = newItem();
	item1->payload = 5;
	addQueue(&q1, item1);
	element *item2 = newItem();
	item2->payload = 20;
	addQueue(&q1, item2);
	element *item3 = newItem();
	item3->payload = 50;
	addQueue(&q1, item3);
	printQueue(&q1);
	element *q2 = newItem();
	initQueue(&q2);
	element *item4 = newItem();
	element *item5 = newItem();
	element *item6 = newItem();
	item4->payload = 1;
	item5->payload = 2;
	item6->payload = 3;
	addQueue(&q2, item4);
	addQueue(&q2, item5);
	addQueue(&q2, item6);
	printQueue(&q2);

	return 0;
}