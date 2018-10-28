#include <stdio.h>

struct ringBuffer {
	int Buffer[10];
	int *head;
	int *tail;
};

int main(void)
{
	struct ringBuffer ringBuffer;
	int i;
	ringBuffer.head = ringBuffer.Buffer[0];
	for(i=0; i<10; i++) {
		ringBuffer.Buffer[i] = i;
		
		printf("%d ", ringBuffer.Buffer[i]);
	}
	printf("\n");
	return 0;
}
