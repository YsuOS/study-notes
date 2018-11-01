#include <stdio.h>

#define SIZE 10

struct ringBuffer {
	char buffer[SIZE];
	int head;
	int tail;
};

void printQueue(struct ringBuffer *q)
{
	int i;

	printf("head[%d], tail[%d]\n", q->head, q->tail);
	printf("[i]: 9 8 7 6 5 4 3 2 1 0\n");
	printf("************************\n");
	printf("     ");
	for(i=0; i<SIZE; i++) {
		printf("%c ", q->buffer[i]);
	}
	printf("\n\n");
}
	
void enqueue(struct ringBuffer *q, int number)
{
	char item = '0' + number;
	if (q->buffer[q->tail] == '_') {
		q->buffer[q->tail] = item;
		q->tail = (q->tail + SIZE - 1) % SIZE;
	}
}

int dequeue(struct ringBuffer *q)
{
	char item;
	if (q->buffer[q->tail] != '_') {
		item = q->buffer[q->head];
		q->buffer[q->head] = '_';
		q->head = (q->head + SIZE - 1) % SIZE;
	}
	return item;
}

int main(void)
{
	struct ringBuffer queue;
	int i;

	//initialize queue
	queue.head = 0;
	queue.tail = 0;
	for(i=0; i<SIZE; i++)
		queue.buffer[i] = '_';
	printQueue(&queue);

	for (i=0; i<20; i++){
		enqueue(&queue, i);
		printQueue(&queue);
	}
	printf("dequeue: %c\n", dequeue(&queue));
	printQueue(&queue);
	
	return 0;
}
