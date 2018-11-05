#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int makeRand(void) {
	int s;
	s = rand() % 10;
	return s;
}

struct ringBuffer {
	char buffer[SIZE];
	int head;
	int tail;
};

void printQueue(struct ringBuffer *q)
{
	int i;

	printf("head[%d], tail[%d] ", q->head, q->tail);
//	printf("[i]: 0 1 2 3 4 5 6 7 8 9\n");
//	printf("************************\n");
//	printf("     ");
	for(i=0; i<SIZE; i++) {
		printf("%c ", q->buffer[i]);
	}
//	printf("\n");
}
	
void enqueue(struct ringBuffer *q, int number)
{
	char item = '0' + number;
	if (q->buffer[q->tail] == '_') {
		q->buffer[q->tail] = item;
		q->tail = (q->tail + SIZE - 1) % SIZE;
		printQueue(q);
		printf(" <= %c  (enqueue)\n", item);
	} else {
		printf("failed to enqueue\n");
	}
}

void dequeue(struct ringBuffer *q)
{
	char item;
	if (q->buffer[q->head] != '_') {
		item = q->buffer[q->head];
		q->buffer[q->head] = '_';
		q->head = (q->head + SIZE - 1) % SIZE;
		printQueue(q);
		printf(" => %c  (dequeue)\n", item);
	} else {
		printf("failed to dequeue\n");
	}
}

int main(void)
{
	struct ringBuffer queue;
	int i, s;
	srand(time(NULL));

	//initialize queue
	queue.head = 0;
	queue.tail = 0;
	for(i=0; i<SIZE; i++)
		queue.buffer[i] = '_';
	printQueue(&queue);
	printf(" Initialize\n");
	for (i=0; i<5; i++) {
		s = makeRand();
		enqueue(&queue, s);
	}
	printf("\n\n");

	for (i=0; i<20; i++){
		s = makeRand();
		if (s % 2 == 0) {
			enqueue(&queue, s);
		} else {
			dequeue(&queue);
		}
	}
	
	return 0;
}
