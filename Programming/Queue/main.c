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
	for(i=0; i<SIZE; i++) {
		printf("%c ", q->buffer[i]);
	}
	printf("\n");
}
	
void enqueue(struct ringBuffer *q, int number)
{
	char item = '0' + number;
	if (q->buffer[q->tail] == '_') {
		q->buffer[q->tail] = item;
		if (q->tail == 0) 
			q->tail = SIZE - 1;
		else
			q->tail--;
	}
}

int dequeue(struct ringBuffer *q)
{
	char item;
	item = q->buffer[q->head];
	q->buffer[q->head] = '_';
	if (q->head == 0)
		q->head = SIZE - 1;
	else
		q->head--;
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
