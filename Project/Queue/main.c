#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int makeRand(void) {
	int s;
	s = rand() % 10;
	return s;
}

typedef struct {
	char buffer[SIZE];
	int head;
	int tail;
}Queue;

void printQueue(Queue *q)
{
	int i;

	printf("head[%d], tail[%d] ", q->head, q->tail);
	for(i=0; i<SIZE; i++) {
		printf("%c ", q->buffer[i]);
	}
}

int isFull(Queue *q)
{
	if (q->buffer[q->tail] != '_' && q->head == q->tail)
		return 1;
	else
		return 0;
}

int isEmpty(Queue *q)
{
	if (q->buffer[q->head] == '_' && q->head == q->tail)
		return 1;
	else
		return 0;
}
void enqueue(Queue *q, int number)
{
	char item = '0' + number;
	if (!isFull(q)) {
		q->buffer[q->tail] = item;
		q->tail = (q->tail + SIZE - 1) % SIZE;
		printQueue(q);
		printf(" <= %c  (enqueue)\n", item);
	} else {
		printf("failed to enqueue\n");
	}
}

void dequeue(Queue *q)
{
	char item;
	if (!isEmpty(q)) {
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
	Queue queue;
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
