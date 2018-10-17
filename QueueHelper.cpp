#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;

};

struct node *front = NULL;
struct node *rear = NULL;



void display()
{
	struct node *temp;
	temp = front;
	printf("\n");
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}


void enqueue(int item)
{
	struct node *nptr = malloc(sizeof(struct node));
	nptr->data = item;
	nptr->next = NULL;
	if (rear == NULL)
	{
		front = nptr;
		rear = nptr;
	}
	else
	{
		rear->next = nptr;
		rear = rear->next;
	}
}

