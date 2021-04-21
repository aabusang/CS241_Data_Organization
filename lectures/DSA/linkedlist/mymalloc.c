#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i,  *p;

    printf("Enter size of array: ");
    scanf("%d", &n);

    p = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
	p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
	printf("i = %d, p[%d] = %d, address of p[%d] = %p\n", i, i, p[i], i, (p + i) );
    }

    free(p);
    

    return 0;
}
