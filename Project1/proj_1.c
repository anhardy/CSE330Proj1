#include "q.h"

/*
Prints all elements in queue
*/
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

/*
This test function deletes all items from a queue.
Prints payload of each item deleted upon each deletion,
followed by values of remaining payloads in the queue.
*/
void emptyQueue(element **head) {
	element *tempHead = *head;
	element *tempQueue = *head;

	int returnedValue = 0;

	//Delete first queue item if queue is not empty.
	if (head != NULL) {

		element *temp = delQueue(head);
		returnedValue = (int)temp->payload;
		printf("Value returned is %d\n", +returnedValue);
		printf("Remaining payload values in the queue are: \n");
		printQueue(head);


		//Initiate Boolean value for an empty queue to -1(not empty).
		int queueEmpty = -1;

		//Delete remaining queue items.
		while (queueEmpty != 1)
		{
			element *temp = delQueue(head);
			returnedValue = (int)temp->payload;

			//Test if the temp's next value is itself.
			if (temp->next == temp) {

				queueEmpty = 1;
			}
			printf("Value returned is %d\n", +returnedValue);

			if (queueEmpty != 1)
			{

				tempQueue = tempQueue->next;

				printf("Remaining payload values in the queue are: \n");
				printQueue(head);
			}

			if (queueEmpty == 1) {

				printf("There are no remaining values in the queue.\n");
				printf("\n");
			}

		}
	}
}


int main() {
	element *q1 = newItem();
	initQueue(&q1);
	element *item1 = newItem();
	element *item2 = newItem();
	element *item3 = newItem();
	item1->payload = 5;
	item2->payload = 20;
	item3->payload = 50;
	addQueue(&q1, item1);
	addQueue(&q1, item2);
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

	element *q3;
	initQueue(&q3);
	element *item7 = newItem();
	element *item8 = newItem();
	element *item9 = newItem();
	element *item10 = newItem();
	item7->payload = -3;
	item8->payload = -2;
	item9->payload = -1;
	item10->payload = 0;
	addQueue(&q3, item7);
	addQueue(&q3, item8);
	addQueue(&q3, item9);
	addQueue(&q3, item10);

	printQueue(&q3);

	//test deleting and adding items 
	delQueue(&q1);
	printQueue(&q1);
	element *newElement = newItem();
	newElement->payload = 999;
	addQueue(&q1, newElement);
	printQueue(&q1);
	
	//test deleting queues
	printf("Deleting all items from q3:\n");
	emptyQueue(&q3);

	printf("Deleting all items from q2:\n");
	emptyQueue(&q2);

	printf("Deleting all items from q1:\n");
	emptyQueue(&q1);
	
	element *newQueueTest = newItem();
	newQueueTest->payload = 25;
	addQueue(&q1, newQueueTest);
	printQueue(&q1);
	delQueue(&q1);
	newQueueTest->payload = 55;
	addQueue(&q1, newQueueTest);
	printQueue(&q1);


	return 0;
}