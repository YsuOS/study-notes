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
	if(heap[i] == '-'){
		heap[i] = makeRand() + '0';
		if((i-1)/2 != '-' && heap[i] < heap[(i-1)/2]){
			tmp = heap[i];
			heap[i] = heap[(i-1)/2];
			heap[(i-1)/2] = tmp;
		}			
		printHeap(heap);
	}
}

int main(void)
{
	char heap[SIZE];
	int i,j,k;
	srand(time(NULL));
	for(i=0; i<SIZE; i++){
		heap[i] = '-';
	}
	k=0;
	for(i=0; 2*i+2<=SIZE; i++){
		for(j=i;j<pow(2,k);j++)
			insert(heap, j);
		k++;
	}
	
	return 0;
}
