/***************************
 *By: Adam Abusang
 *A program to convert binary file to it's ascii equivalent
 *and count number of characters per line, number of lines
 *and total characters
 **************************/

#include <stdio.h>

#define IN 1 /*inside word*/
#define OUT 0 /*outside a word*/

int main(void)
{
  int dec = 0, i = 0;
  int state = OUT;
  char c;
 
  int lineCount = 0;
  int charCount = 0;
  int totalChar = 0;
  int wordCount = 1;

  while((c = getchar()) != EOF)
   {
     i++;
    
     if (c == '\n')
     {
       lineCount++;
       printf(" (%d, %d)\n", lineCount, charCount);
       totalChar += charCount;
       charCount = 0;
     }
     if (c == ' ' || c == '\n' || c == '\t')
     {
       state = OUT;
     }
     if (state == OUT)
     {
       state = IN;
       wordCount++;
     }
     if (c == '1')
     {
       dec = dec * 2 + 1;
     } 
     if (c == '0')
     {
       dec = dec * 2;
     }
     if (i == 8)
     {
       printf("%c", dec);
       i = 0;
       charCount++;
     }
   }
  printf("\n\nThere are %d characters, %d words, %d lines\n",
	 totalChar, wordCount, lineCount);

  return 0;
}
