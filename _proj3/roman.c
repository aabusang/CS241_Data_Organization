#include <stdio.h>

/**
 *By: Adam Abusang
 *A program to convert ascii characters to
 *their roman numeral equivalent
**/
int main(void)
{

  int c;
  int oneth = 0, tenth = 0, hundredth = 0;

  while((c = getchar()) != EOF)
  {

    if (c == '\n')
    {
      printf("%c", c);
      continue;
    }
    if (c < 100)
    {
      /*get the oneth value*/
      oneth = c % 10;
      /*get the tenth value*/
      tenth = c / 10;
      switch(tenth)
      {
	/*
	 * values are b/n 32 and 125
	 *so start at 3 for tenth
	 */
      case 3:
	printf("XXX");
	break;
      case 4:
	printf("XL");
	break;
      case 5:
	printf("L");
	break;
      case 6:
	printf("LX");
	break;
      case 7:
	printf("LXX");
	break;
      case 8:
	printf("LXXX");
	break;
      case 9:
	printf("XC");
	break;
      }

      
      switch(oneth)
      {
      case 1:
	printf("I");
	break;
      case 2:
	printf("II");
	break;
      case 3:
	printf("III");
	break;
      case 4:
	printf("IV");
	break;
      case 5:
	printf("V");
	break;
      case 6:
	printf("VI");
	break;
      case 7:
	printf("VII");
	break;
      case 8:
	printf("VIII");
	break;
      case 9:
	printf("IX");
	break;
      }
      printf(" ");
      
      
    }
    else
    {
      oneth = c % 10;
      /*remove he last value
       *like take 1 from 101
       *now have 10
       */
      tenth = c / 10;
      /*
       *remove the first value
       *like take 1 from 10
       *now have 0
       */
      tenth = tenth % 10;
      hundredth = c / 100;

      switch(hundredth)
      {
      case 1:
	printf("C");
	break;
      }

      switch(tenth)
      {
      case 1:
	printf("X");
	break;
      case 2:
	printf("XX");
	break;
      case 3:
	printf("XXX");
	break;
      case 4:
	printf("XL");
	break;
      case 5:
	printf("L");
	break;
      case 6:
	printf("LX");
	break;
      case 7:
	printf("LXX");
	break;
      case 8:
	printf("LXXX");
	break;
      case 9:
	printf("XC");
	break;
      }

      switch(oneth)
      {
      case 1:
	printf("I");
	break;
      case 2:
	printf("II");
	break;
      case 3:
	printf("III");
	break;
      case 4:
	printf("IV");
	break;
      case 5:
	printf("V");
	break;
      case 6:
	printf("VI");
	break;
      case 7:
	printf("VII");
	break;
      case 8:
	printf("VIII");
	break;
      case 9:
	printf("IX");
	break;
      }
      printf(" ");
    }


  }
  return 0;  
}
