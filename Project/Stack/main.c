#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int makeRand(void) {
	int s;
	s = rand() % 10;
	return s;
}

typedef struct Stack{
	char buffer[SIZE];
	int top;
}Stack;

void printStack(Stack *s)
{
	int i;

	if (s->top >= 0)
		printf("top[%d] ", s->top);
	else
		printf("top[-] ");
	for(i=0; i<SIZE; i++) {
		printf("%c ", s->buffer[i]);
	}
}
	
void push(Stack *s, int number)
{
	char item = '0' + number;

	if (s->top + 1 < SIZE) {
		s->buffer[++s->top] = item;
		printStack(s);
		printf(" <= %c  (push)\n", item);
	} else {
		printf("failed to push\n");
	}
}

void pop(Stack *s)
{
	char item;

	if (s->top >= 0) {
		item = s->buffer[s->top];
		s->buffer[s->top--] = '_';
		printStack(s);
		printf(" => %c  (pop)\n", item);
	} else {
		printf("failed to pop\n");
	}
}

int main(void)
{
	Stack stack;
	int i, s;
	srand(time(NULL));

	//initialize stack
	stack.top = -1;
	for(i=0; i<SIZE; i++)
		stack.buffer[i] = '_';
	printStack(&stack);
	printf(" Initialize\n");
	for (i=0; i<5; i++) {
		s = makeRand();
		push(&stack, s);
	}
	printf("\n\n");

	for (i=0; i<20; i++){
		s = makeRand();
		if (s % 2 == 0)
			push(&stack, s);
		else
			pop(&stack);
	}
	
	return 0;
}
