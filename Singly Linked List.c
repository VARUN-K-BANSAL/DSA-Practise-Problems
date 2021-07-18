#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
	int visited;
} SLL;

SLL *head = NULL;

// functions declaration
SLL *createList();
SLL *reverseList(SLL *head);
SLL *reverseListInParts(SLL *head);
int checkForCycles(SLL *head);
int checkForCyclesFloydAlgorithm(SLL *head);
void printList();
void clearList();

// main function
int main()
{
	srand((unsigned int) time(NULL));

	head = createList();
	printf("List ->\n");
	printList();
	
	head = reverseList(head);
	printf("Reversed List ->\n");
	printList();

	// for getting original List
	head = reverseList(head);

	head = reverseListInParts(head);
	printf("Partially Reversed List ->\n");
	printList();

	if(checkForCycles(head))
	{
		printf("Loop Found in the List\n");
	}
	else
	{
		printf("Loop Not Found in the List\n");
	}

	if(checkForCyclesFloydAlgorithm(head))
	{
		printf("Loop Found in the List (Using Floyd Algorithm)\n");
	}
	else
	{
		printf("Loop Not Found in the List (Using Floyd Algorithm)\n");
	}

	// clearing the list
	clearList();

	return 0;
}

int checkForCyclesFloydAlgorithm(SLL *head)
{
	SLL *slow = head;
	SLL *fast = head;

	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			return 1;
	}
	return 0;
}

int checkForCycles(SLL *head)
{
	SLL *temp = head;
	while(temp != NULL)
	{
		if(temp->visited == 1)
		{
			return 1;
		}
		temp->visited = 1;
		temp = temp->next;
	}
	return 0;
}

SLL *reverseListInParts(SLL *head)
{
	// k is the number of nodes in groups we are reversing
	int k = 3;

	// creating three pointers
	SLL *curr = head;
	SLL *next = NULL;
	SLL *prev = NULL;

	int count = 0;

	while(curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(next != NULL)
	{
		head->next = reverseListInParts(next);
	}

	return prev;
}

SLL *reverseList(SLL *head)
{
	// creating three pointers
	SLL *curr = head->next;
	SLL *next = curr->next;
	SLL *prev = head;

	// removing the link for the first node or last node in reversed list
	head->next = NULL;

	while(next != NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}

	// creating the head connections
	curr->next = prev;
	head = curr;
	return head;
}

SLL *createList()
{
	int n = 15;
	for(int i=0; i<n; i++)
	{
		if(head == NULL)
		{
			head = (SLL*) malloc(sizeof(SLL*));
			head->data = 1 + rand()%100;
			head->visited = 0;
			head->next = NULL;
		}
		else
		{
			SLL *node = (SLL*) malloc(sizeof(SLL*));
			node->data = 1+rand()%100;
			node->visited = 0;
			node->next = head;
			head = node;
		}
	}
	return head;
}

void clearList()
{
	SLL *temp = head;
	while(head != NULL)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
	free(head);
}

void printList()
{
	SLL *curr = head;
	while(curr != NULL)
	{
		printf("%d -> ",curr->data);
		curr = curr->next;
	}
	printf("NULL\n\n");
}
