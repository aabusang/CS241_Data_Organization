/******************
 *By: Adam Abusang
 *A program to mutate dna using linked list
 ************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
}node;
/*head of the linked list*/
node *head = NULL;

void addNode(int number);
void changeNode(int element, int index);
void deleteNode(int position);

void sort(int *arr, int size);
void printlist();
void freelist();


int main(int argc, char *argv[])
{
  int i, number, character, listlen = 0;
  int delCount = 0, swapCount = 0;
  char *string, *endPtr;
  int len, base10 = 10, first, mid, last;
  int value, position, delArrMax = 1, swapArrMax = 1;
  int *deleteArr = malloc(sizeof(int));
  int *swapArr = malloc(sizeof(int));
  char *swapPtr = malloc(sizeof(char));
  int *tmpArr;
  
  for (i = 0; i < argc; i++)
  {
    string = argv[i];
    len = strlen(argv[i]);
    first = argv[i][0];
    mid = argv[i][1];
    last = argv[i][len - 1];

    if (len < 2)
    {
      printf("%s: Invalid argv format or length\n", argv[i]);
      return 1;
    }
    if (first == ' ' || last == ' ')
    {
      printf("%s: Extra spaces\n", argv[i]);
      return 2;
    }

    if (first == 'd' && isdigit(last))
    {
      if (delCount == delArrMax)
      {
	tmpArr = realloc(deleteArr, (delArrMax += 1));
	deleteArr = tmpArr;
      }
      number = strtol((string + 1), &endPtr, base10);
      if (number < 0)
      {
	printf("%s: Invalid deletion position\n", argv[i]);
	return 3;
      }
      deleteArr[delCount++] = number;
    }
    
    if (isalpha(first) && isdigit(mid) && isalpha(last))
    {
      if (swapCount == swapArrMax)
      {
	tmpArr = realloc(swapArr, (swapArrMax += 1));
	swapArr = tmpArr;
      }
      number = strtol((string + 1), &endPtr, base10);
      swapArr[swapCount] = number;
      swapPtr[swapCount] = *endPtr;
      swapCount++;
    }
  }

  while ((character = getchar()) != EOF)
  {
    if (character == '\n')
    {
      continue;
    }
    addNode(character);
    listlen++;
  }

  for (i = 0; i < delCount; i++)
  {
    if (deleteArr[i] > listlen)
    {
      printf("Delete position %d is invalid\n",deleteArr[i]);
      return 3;
    }
  }
  for (i = 0; i < swapCount; i++)
  {
    if (swapArr[i] > listlen)
    {
      printf("Swap position %d is invalid\n", swapArr[i]);
      return 3;
    }
  }

  /***
   *Swapping and deletion
   **********************/
  for (i = 0; i < swapCount; i++)
  {
    position = swapArr[i];
    value = swapPtr[i];
    changeNode(value, position);
  }

  sort(deleteArr, delCount);
  for (i = delCount - 1; i >= 0; i--)
  {
    position = deleteArr[i];
    deleteNode(position);
  }

  printlist();

  free(deleteArr);
  free(swapArr);
  freelist(head);
  
  return 0;
}

/**************
 *adds node to a linked list
 *returns notthing
 *******************/
void addNode(int number)
{
  node *new_node = malloc(sizeof(node));
  node *current = head;

  new_node->data = number;
  new_node->next = NULL;

  if (new_node == NULL)
  {
    exit(0);
  }
  if (head == NULL)
  {
    head = new_node;
  }
  else
  {
    while(current->next)
    {
      current = current->next;
    }
    current->next = new_node;
  }
}

/**************
 *update the data of a node
 *returns nothing
 *********************/
void changeNode(int element, int index)
{
    node *current = head;
    int count = 1;
    while(count != index)
    {
        if(current->next)
	{
            current = current->next;
	}
        count++;
    }
    current->data = element;
}

/****************
 *sorts an integer array
 *returns nothing
 *******************/
void sort(int *arr, int size)
{
  int i, j, tmp;
  for (i = 0; i < size; i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if (arr[i] > arr[j])
      {
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
      }
    }
  }
}

/*****************
 *delete a node from a linked list
 *returns nothing
 *********************/
void deleteNode(int position)
{
  int i;
  node *temp = head;
  node *toBeDeleted; /*node to be deleted*/

  for (i = 0; i < position - 2; i++) 
  {
    temp = temp->next; /*node before node to be delete*/
  }

  toBeDeleted = temp->next; 
  temp->next = toBeDeleted->next;
  free(toBeDeleted);
}

/**************
 *formate printing of amino acids
 *returns nothing
 ****************/
void spacedNumbers(int firstNumber)
{
  int i;
  int space = 0;
 
  int number = firstNumber;
  for (i = 1; i <= 5; i++)
  {
    number += 10;
    if (i == 1)
    {
      printf("%10d",number);
    }
    else
    {
      if (number <= 1270)
      {
	printf("%11d",number);
      }
      else
      {
	space = 32;
       	printf("%11c", space);
      }
    }
  }
  printf("\n");
}

/*******************
 *print data of a linked list in formatted way
 *returns nothing
 **************************/
void printlist()
{
  node *current = head;
  int i = 1, c;
  
  printf("Spike protein sequence for B.1.1.7:\n");
  spacedNumbers(0);

  while(current)
  {
    c = current->data;

    if ((i % 10 ) == 0)
    {
      if (((i % 50) == 0) || (i > 1260))
      {
	printf("%c", c);
      }
      else
      {
	printf("%c ", c);
      }
    }
    if ((i % 10) != 0)
    {
      printf("%c", c);
    }
    if ((i % 50) == 0)
    {
      printf("\n");
      spacedNumbers(i);
    }

    current = current->next;
    i++;
  }
  printf("\n");
}
/*frees a linked list*/
void freelist()
{
  node *tmp;
  while(head)
  {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}
