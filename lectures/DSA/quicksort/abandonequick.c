#include <stdio.h>

int arraySize, level;

void quicksort(int vector[], int left, int right);
void printArray(int levelCode, int vector[], int left, int right);

int main(void)
{
    int vector[] = {23, 13, 82, 33, 51, 17, 45, 75, 11, 27};
    arraySize = (sizeof(vector) / sizeof(vector[0]));
    level = 0;
    quicksort(vector, 0, arraySize - 1);
}

void swap(int vector[], int i, int j)
{
    int tmp = vector[i];
    vector[i] = vector[j];
    vector[j] = tmp;
}
    
void quicksort(int vector[], int left, int right)
{
    int i, last;
    void swap(int vector[], int i, int j);

    if (left > right)
	return;
    swap(vector, left, (left + right)/2);
    last = left;
    
    for (i = left + 1; i <= right; i++)
	if (vector[i] < vector[left])
	    swap(vector, ++last, i);
	
    swap(vector, left, last);
    quicksort(vector, left, (last - 1));
    quicksort(vector, (last + 1), right);
    
}

void printArray(int levelCode, int vector[], int left, int right)
{
    int i = 0;
    if (levelCode < 0)
	printf("   Done%d [", -levelCode);
    else
	printf("Level = %2d[", levelCode);

    for (i = 0; i < arraySize; i++)
	if (i < left || i > right)
	    printf("   ");
	else
	    printf("%2d  ", vector[i]);
    
    printf("]\n");
	
}
