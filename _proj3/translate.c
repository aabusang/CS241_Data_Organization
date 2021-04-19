#include <stdio.h>

/**
 *By: Adam Abusang
 *A program to translate roman numerals to 
 *their ascii value equivalent and print 
 *them out
**/

int main(void)
{
  /*
   *I and X are the 2 roman 
   *numerals that comes before
   *other numbers between 32 and 125
   *so I will use that to help solve this
   *prolem, making @prevI 1 if the previous
   *char was an I else keep it 0. And same for X
   */
  int c;
  int prevI = 0, prevX = 0;
  int total = 0, number = 0;
  
  while((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      printf("%c", c);
      continue;
    }
    while (c > 32)
    {
      switch(c)
      {
      case 'I':
	number = 1;
	total += 1;
	break;
      case 'V':
	number = 5;
	total += 5;
	break;
      case 'X':
	number = 10;
	total += 10;
	break;
      case 'L':
	number = 50;
	total += 50;
	break;
      case 'C':
	number = 100;
	total += 100;
	break;
      }

      if (c == 'I')
      {
	prevI = 1;
      }
      else
      {
	if (prevI == 1)
	{
	  if (number > 1)
	  {
	    total -= 2;
	  }
	  prevI = 0;
	}
      }
          
     if (c == 'X')
     {
       prevX = 1;
     }
     else
     {
       if (prevX == 1)
       {
	 if (number > 10)
	 {
	   total -= 20;
 	 }
	 prevX = 0;
       }
     }

     c = getchar();
    }
    printf("%c", total);
    total = 0;
    prevI = 0;
    prevX = 0;
  
  }
    
  return 0;
}
