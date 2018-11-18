#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int makeRand(void) {
	int s;
	s = rand() % 10;
	return s;
}

void insert(char *heap, int i)
{
	if(heap[2*i+1] == '-')
		heap[2*i+1] = makeRand() + '0';
	if(heap[2*i+2] == '-')
		heap[2*i+2] = makeRand() + '0';
}

void printHeap(char *heap)
{
	int i;

	for(i=0; i<SIZE; i++) {
		printf("%c ", heap[i]);
	}
	printf("\n");
}
	
int main(void)
{
	char heap[SIZE];
	int i;
	srand(time(NULL));
	for(i=0; i<SIZE; i++){
		heap[i] = '-';
	}
	heap[0] = makeRand() + '0';

	for(i=0; i<SIZE; i++){
		insert(heap, i);
	}
	printHeap(heap);
	
	return 0;
}
