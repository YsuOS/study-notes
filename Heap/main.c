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
		printf("insert:%c\n", heap[i]);
		if(i == 0){
			printHeap(heap);
			return;
		}
		while(i != 0){
			if((i-1)/2 != '-' && heap[i] < heap[(i-1)/2]){
				tmp = heap[i];
				heap[i] = heap[(i-1)/2];
				heap[(i-1)/2] = tmp;
				i = (i - 1)/2;
				printHeap(heap);
			}else{
				printHeap(heap);
				break;
			}
		}
	}
}

void pop(char *heap)
{
	int i;
	char tmp;
	i=SIZE-1;
	printf("pop:%c\n", heap[0]);
	heap[0] = '-';
	printHeap(heap);
	while(heap[i]=='-')
		i--;
	heap[0] = heap[i];
	heap[i] = '-';
	printHeap(heap);
	i = 0;
	while(2*i+2<SIZE){
		if(heap[2*i+1] <= heap[2*i+2] && heap[i] > heap[2*i+1]){
			tmp = heap[i];
			heap[i] = heap[2*i+1];
			heap[2*i+1] = tmp;
			i = 2*i+1;
			printHeap(heap);
		}else if(heap[2*i+1] > heap[2*i+2] && heap[i] > heap[2*i+2]){
			tmp = heap[i];
			heap[i] = heap[2*i+2];
			heap[2*i+2] = tmp;
			i = 2*i+2;
			printHeap(heap);
		}else{
			break;
		}
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
	i=k=0;
	while(i<SIZE){
		for(;i<pow(2,k);i++)
			insert(heap, i);
		k++;
	}
	pop(heap);
	
	return 0;
}
