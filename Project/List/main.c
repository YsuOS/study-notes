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
	printf("(tail) ");
	while(head->next != NULL){
		head = head->next;
		printf("-> %c ", head->value);
	}
	printf("\n", head->value);
	

}
void push(node_t *tail)
{
	node_t *head;
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->value = '0' + makeRand();

	if(tail->next == NULL) {
		head = tail;	
	} else {
		head = tail->next;
		while(head->next != NULL){
			head = head->next;
		}
	}
	head->next = new_node;
	new_node->next = NULL;
}
// remove; remove node
int main(void)
{
	int i;
	node_t tail;
	srand(time(NULL));
	tail.next = NULL;

	for(i=0; i<5; i++)
		push(&tail);

	printList(&tail);

	return 0;
}
