#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
	int i,l,x;
	l = x = 0;

	// new line's condition for printing heap
	// l(x) = 2^x + l(x-1)
	// l(0) = 0
	for(i=0; i<SIZE; i++) {
		printf("%c ", heap[i]);
		if(i == 0 || i == pow(2, x) + l){
			printf("\n");
			if(i != 0)
				l = pow(2, x) + l;
			x++;
		}
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
