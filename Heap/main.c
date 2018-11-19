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
	
void push(char *heap)
{
	char tmp;
	int i=0;
	while(heap[i] != '-')
		i++;
	heap[i] = makeRand() + '0';
	printf("insert:%c\n", heap[i]);
	printHeap(heap);
	if(i == 0)
		return;
	while(i != 0){
		if((i-1)/2 != '-' && heap[i] < heap[(i-1)/2]){
			tmp = heap[i];
			heap[i] = heap[(i-1)/2];
			heap[(i-1)/2] = tmp;
			i = (i - 1)/2;
			printHeap(heap);
		}else{
			break;
		}
	}

}

void pop(char *heap)
{
	int i,j=0;
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
	while(2*j+1<i){
		if(heap[2*j+1] <= heap[2*j+2] && heap[j] > heap[2*j+1]){
			tmp = heap[j];
			heap[j] = heap[2*j+1];
			heap[2*j+1] = tmp;
			j = 2*j+1;
			printHeap(heap);
		}else if(heap[2*j+1] > heap[2*j+2] && heap[j] > heap[2*j+2]){
			tmp = heap[j];
			heap[j] = heap[2*j+2];
			heap[2*j+2] = tmp;
			j = 2*j+2;
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
		push(heap);
		i++;
	}
	pop(heap);
	pop(heap);
	push(heap);
	
	return 0;
}
