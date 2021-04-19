#include <stdio.h>
#include <string.h>

int main(void)
{
    char binary[8] = {0};

    int decimal, remainder, quotient, i = 0;
    printf("Convert decimal to binary\n");
    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    while (1)
    {
	remainder = decimal % 2;
	binary[i++] = remainder;
	quotient = decimal / 2;
	if (quotient <= 0)
	{
	    break;
	}
	decimal = quotient;
    }

    printf("Len: %lu\n", strlen(binary));
    for (i = 0; i < strlen(binary); i++)
    {
	printf("%c", binary[i]);
    }
    printf("\n");
}
