#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

//minimum heap tree

int makeRand(void) {
	int s;
	s = rand() % 10;
	return s;
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
	printf("\n\n");
}
	
void insert(char *heap, int i)
{
	char tmp;
	if(heap[0] == '-'){
		heap[0] = makeRand() + '0';
		printHeap(heap);
		return;
	}else if(heap[2*i+1] == '-'){
		heap[2*i+1] = makeRand() + '0';
		if(heap[2*i] > heap[2*i+1]){
			tmp = heap[2*i];
			heap[2*i] = heap[2*i+1];
			heap[2*i+1] = tmp;
		}
		printHeap(heap);
		return;
	}else if(heap[2*i+2] == '-'){
		heap[2*i+2] = makeRand() + '0';
		if(heap[2*i] > heap[2*i+2]){
			tmp = heap[2*i];
			heap[2*i] = heap[2*i+2];
			heap[2*i+2] = tmp;
		}
		printHeap(heap);
		return;
	}
}

int main(void)
{
	char heap[SIZE];
	int i,j;
	srand(time(NULL));
	for(i=0; i<SIZE; i++){
		heap[i] = '-';
	}

	for(i=0; 2*i+2<=SIZE; i++){
		for(j=1;j<=pow(2, i);j++)
			insert(heap, j);
	}
	
	return 0;
}
