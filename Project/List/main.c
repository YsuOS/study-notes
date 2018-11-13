#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeRand(void) {
	int s;
	s = rand() % 10;
	return s;
}

typedef struct node{
	char value;
	struct node *next;
}node_t;
void printList(node_t *tail)
{
	node_t *head = tail;
	while(head->next != NULL){
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n", head->value);
	

}
void push(node_t *tail)
{
	node_t *head = tail;
	while(head->next != NULL){
		head = head->next;
	}
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->value = makeRand();
	head->next = new_node;
	new_node->next = NULL;
}
// remove; remove node
// print; print linked list
int main(void)
{
	node_t tail;
	srand(time(NULL));
	tail.next = NULL;

	push(&tail);
	push(&tail);

	printList(&tail);

	return 0;
}
