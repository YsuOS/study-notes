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
	printf("\n");
	

}

void push(node_t *tail)
{
	node_t *head;
	node_t *new_node = (node_t *)malloc(sizeof(node_t));

	new_node->value = '0' + makeRand();
	new_node->next = NULL;
	head = tail;	
	while(head->next != NULL)
		head = head->next;
	head->next = new_node;
}

void pop(node_t *tail)
{
	node_t *head;

	head = tail;
	if (head->next == NULL)
		return;
	while(head->next->next != NULL)
		head = head->next;
	printf("pop %c\n", head->next->value);
	free(head->next);
	head->next = NULL;
}

// insert; insert a new node to * place from tail(except tail)
void insert(node_t *tail, int n)
{
	node_t *p;
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	if(n <= 0){
		free(new_node);
		return;
	}
	new_node->value = '0' + makeRand();
	new_node->next = NULL;
	p = tail;
	printf("insert %c to %d place from tail\n", new_node->value, n);
	while(--n != 0 && p->next != NULL)
		p = p->next;
	if(n != 0){
		free(new_node);
		return;
	}
	new_node->next = p->next;	
	p->next = new_node;

}
// remove; remove a node from * place from tail(except tail)
void remove_node(node_t *tail, int n)
{
	node_t *p;
	int tmp = n;

	p = tail;
	if(n <= 0 || p->next == NULL)
		return;
	while(--n != 0 && p->next != NULL)
		p = p->next;
	printf("remove %c to %d place from tail\n", p->next->value, tmp);
	free(p->next);
	p->next = p->next->next;
}

int main(void)
{
	int i;
	node_t tail, *p;
	srand(time(NULL));
	tail.next = NULL;

	for(i=0; i<5; i++){
		push(&tail);
		printList(&tail);
	}
	for(i=0; i<2; i++){
		pop(&tail);
		printList(&tail);
	}
	insert(&tail,2);
	printList(&tail);
	insert(&tail,4);
	printList(&tail);
	insert(&tail,8);
	printList(&tail);
	remove_node(&tail,3);
	printList(&tail);

	//free memory of all nodes
	p = &tail;
	while(p->next != NULL){
		p = p->next;
		free(p);
	}
	return 0;
}
