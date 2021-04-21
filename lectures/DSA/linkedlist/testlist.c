#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List
{
  int c;
  struct List *next;
}node;

node *head = NULL;

void addNode(int number);
void printlist(node *list);

int main(int argc, char *argv[])
{
  int c;
  while((c = getchar()) != EOF)
  {
    addNode(c);
  }
  
  printlist(head);
}


void addNode(int number)
{
  node *new_node = malloc(sizeof(node));
  if (new_node == NULL)
  {
    printf("No more space for another node\n");
    exit(0);
  }

  new_node->c = number;
  new_node->next = NULL;

  node *current = head;
  
  if (head == NULL)
  {
    head = new_node;
  }
  else
  {
    while(current->next != NULL)
    {
      current = current->next;
      break;
    }
    current->next = new_node;
  }
}

/*
void addNode(int number)
{
  node *new_node = malloc(sizeof(node));
  if (new_node == NULL)
  {
    printf("No space for another node\n");
  }
  else
  {
    new_node->c = number;
    new_node->next = NULL;

    if(head == NULL)
    {
      head = new_node;
    }
    else
    {
      //both head and current are on the same line
      node *current = head;
      while(true)
      {
	if (current->next == NULL)
	{
	  //current, now at the end of head, points to new node
	  current->next = new_node;
	  break;
	}
	current = current->next;
      }
    }
  }
}
*/

void printlist(node *list)
{
  node *tmp = list;
  while(tmp->next != NULL)
  {
    printf("%c", tmp->c);
    tmp = tmp->next;
  }
  printf("\n");
}
