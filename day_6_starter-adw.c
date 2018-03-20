/**********************************************************************
Program: Reverse linked list program
Author: Andrew Watts
Date: 10/1/2017
Time spent: 1 hour
Purpose: The purpose of this program is to reverse a linked list.
The program starts counting off from the list of nodes whose values are integers starting from 9 all the way down to 0.
The Reverse_list function then proceeds to reverse the previous list by changing links between nodes.
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
Node* Reverse_list (Node * Head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node).


	//print the reversed list.
	head = Reverse_list(head);
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//Define your function here
Node* Reverse_list(Node * Head)
{
	Node *temp1 = NULL, *temp2, *temp3;
	temp2 = Head;
	while (temp2 != NULL)
	{
		temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;

		temp2 = temp3;
	}
	printf("temp->%d->next->%d\n", temp1->data, temp1->next->data);
	Head = temp1;
	return Head;
}