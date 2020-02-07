#include "q.h"

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


	return 0;
}