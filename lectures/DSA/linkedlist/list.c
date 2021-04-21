#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *head = NULL;

void insertAtStart(int number);
void insertAtEnd(int number);
void insert(int number, int position);

void deleteAtStart(int number);
void deleteAtEnd(int number);
void delete(int position);

int listlen(node *list);
void reverseList(node *list);
void printList(node *list);

int main(void)
{
    char name[10] = {'a', 'b', 'u', 'a', 'n', 'g'};
    int dollar = '$';
    int n = 7, position = 3;

    int i;
    for (i = 0; i < n; i++)
    {
	/*for every loop, add a new node to the end of the linked list*/
	/*insertAtStart(name[i]);*/
	insertAtEnd(name[i]);
    }	
    printList(head);

    insert(dollar, position);

    printList(head);

    delete(position);

    printList(head);
    return 0;
}

void delete(int position)
{
    int i = 0;
    node *previous = head;
    node *current;
    if (head == NULL)
    {
	printf("Empty list\n");
	exit(0);
    }
    else
    {
	current = head->next;
	for (; i < position - 1; i++)
	{
	    previous = current;
	    current = current->next;
	}
	previous->next = current->next;
	free(current);
    }
}
void insertAtStart(int number)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
	printf("No more space for new node\n");
    }
    
    new_node->data = number;
    new_node->next = head;
    head = new_node;
}

void insert(int number, int position)
{
    int i = 1;
    int n = listlen(head);
    
    node *tmp = head;
    node *new_node = malloc(sizeof(node));

    if (new_node == NULL)
    {
	printf("No more space for a node\n");
	exit(0);
    }
    new_node->data = number;

    if (head == NULL)
    {
	if (position != 0)
	{
	    exit(0);
	}
	else
	{
	    new_node->next = head;
	    head = new_node;
	}
    }
    else
    {
	for (node *tmp = head; tmp != NULL; i++, tmp = tmp->next)
	{
	    if (i == position)
	    {
		new_node->next = tmp->next;
		tmp->next = new_node;
	    }
	}
    }
}

void insertAtEnd(int number)
{
    node *new_node = malloc(sizeof(node));
    node *current = head;

    if (new_node == NULL)
    {
	printf("No more space for another node\n");
    }
        
    new_node->data = number;
    new_node->next = NULL;
	
    if (head == NULL)
    {
	head = new_node;
    }
    else
    {
	while (current->next != NULL)
	{
	    current = current->next;
	}
	current->next = new_node;
    }
}
int listlen(node *list)
{
    int num = 0;
    for (node *tmp = head; tmp->next != NULL; tmp = tmp->next)
    {
	num++;
    }
    return num;
}
void printList(node *list)
{
    int i = 0, n = listlen(list);
    
	
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
	printf("%c", tmp->data);
    }
    printf("\n");
}
