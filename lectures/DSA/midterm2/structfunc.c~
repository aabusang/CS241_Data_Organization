#include <stdio.h>
#include <stdlib.h>

typedef struct Bar
{
    int data;
    struct Bar *next;
}bar;

bar *push(int number);
void print(bar *h);

int main(void)
{
    int number = 10;
    push(number);
    /* print(); */
}

bar *push(int number)
{
    int i, limit = 10;
    bar *p = NULL;

    for (i = 0; i < limit; i++)
    {
	bar *tmp = malloc(sizeof(bar));
	tmp->data = number - i;
	tmp->next = p;
	p = tmp;
    }
    return p;
}

void print(bar *currentStruct)
{
    while(currentStruct != NULL)
    {
	printf("%d ", currentStruct->data);
	currentStruct = currentStruct->next;
    }
    printf("\n");
}
