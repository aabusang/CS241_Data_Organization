#include <stdio.h>

/*
By: Adam Abusang
A program to convert a text into it's binary equivalent
or encrypt it in other words
*/

int main(void)
{
  int c;
  
  while((c = getchar()) != EOF)
  {
    int i = 7;
    while(i+1 > 0)
    {
      if (c >= (1<<i))
      {
	c = c - (1<<i);
	printf("1");
      }
      else
      {
	printf("0");
      }
      i--;
    }
  }
  /*binary form of \n below gets part of the output*/
  /*  printf("\n");*/
  return 0;
}
