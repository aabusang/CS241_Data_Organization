/****************************
 *Adam Abusang
 *A program to convert roman numbers to
 *their ascii equivalent.
 *The program detect invalid roman numbers 
 *arrangement or invalid roman characters
 ***************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


bool exist(char roman[]);
bool romNum(char roman[]);
int calcAscii(char roman[]);
void reset(char roman[]);

int main(void)
{
  int c, i = 0;
  char roman[16] = {0};
  int ascii = 0;
  bool overLoaded = false;
  
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      printf("\n");
      continue;
    }
    while (c > 32)
    {
      roman[i] = toupper(c);
      i++;
      overLoaded = false;
      if (i > 14)
      {
	overLoaded = true;
      }
      c = getchar();
    }
    
    i = 0;
  
    if (overLoaded)
    {
      printf("[Unable to read character string]");
      reset(roman);
      continue;
    }
    if (!romNum(roman))
    {
      printf("[Error: %s is not a Roman numeral]", roman);
      reset(roman);
      continue;
    }
    if (!exist(roman))
    {
      printf("[Error:Roman numeral %s does not exist]", roman);
      reset(roman);
      continue;
    }
   
    ascii = calcAscii(roman);
    reset(roman); 
  
    if (ascii > 31 && ascii < 126)
    {
      printf("%c", ascii);
    }
    else
    {
      printf("[Error: %d is not a printable ASCII character]", ascii);
    }
  }

  return 0;
}

/***************
 *rtoa = "roman to ascii"
 *rtoa converts and return an integer 
 *value of the roman value @param roman_num
 *or returns -1 of roman_num is not a valid roman number
 ****************/
int rtoa(char roman_num)
{
  int value;
  switch(roman_num)
  {
  case 'I':
    value = 1;
    break;
  case 'V':
    value = 5;
    break;
  case 'X':
    value = 10;
    break;
  case 'L':
    value = 50;
    break;
  case 'C':
    value = 100;
    break;
  case 'D':
    value = 500;
    break;
  case 'M':
    value = 1000;
    break;
  default:
    value = -1;
    break;
  }
  return value;
}
/***************
 *calcAscii calculates and return
 *the decimal equivalent of the
 *the roman number in @param roman[]
 **************/
int calcAscii(char roman[])
{
  bool prevI = false;
  bool prevX = false;
  bool prevC = false;

  int ascii = 0, j;
  for (j = 0; roman[j] != '\0'; j++)
  {
    int current = rtoa(roman[j]);
    ascii += current;
    if (roman[j] == 'I')
    {
      prevI = true;
    }
    else
    {
      if (prevI == true)
      {
	if (current > 1)
	{
	  ascii -= 2;
	}
	prevI = false;
      }
    }
          
    if (roman[j] == 'X')
    {
      prevX = true;
    }
    else
    {
      if (prevX == true)
      {
	if (current > 10)
	{
	  ascii -= 20;
	}
	prevX = false;
      }
    }
    if (roman[j] == 'C')
    {
      prevC = true;
    }
    else
    {
      if (prevC == true)
      {
	if (current > 100)
	{
	  ascii -= 200;
	}
	prevC = false;
      }
    }
  }
  return ascii;
}

/******************
 *romNum returns false if 
 *non-roman numeral is found
 *in @param roman[]
 *******************/
bool romNum(char roman[])
{
  int i;
  for (i = 0; roman[i] != '\0'; i++)
  {
    if (rtoa(roman[i]) == -1)
    {
      return false;
    }
  }
  return true;
}


/*************
 *dvlRule return false if 
 *roman number d, v or l 
 *is repeated in @param roman[]
 *************/
bool dlvRule(char roman[])
{
  int i, d = 0, l = 0, v = 0;
  for (i = 0; roman[i] != '\0'; i++)
  {
    char c = roman[i];
    if (c == 'D')
    {
      d++;
    }
    if (c == 'L')
    {
      l++;
    }
    if (c == 'V')
    {
      v++;
    }
    if (d > 1 || l > 1 || v > 1)
    {
      return false;
    }
  }
  return true;
}

/*******************
 *repeatRule returns false for 
 *invalid number of repititions
 *of roman numerals m, c, x and i
 ******************/
bool repeatRule(char roman[])
{
  int i, M = 0, C = 0, X = 0, I = 0;
  for (i = 0; roman[i] != '\0'; i++)
  {
    char c = roman[i], c1 = roman[i - 1];
    char c2 = roman[i - 2], c3 = roman[i - 3];

    if (c == 'M')
    {
      M++;
      if (c1 == 'M' && c2 == 'M' && c3 == 'M')
      {
	return false;
      }
    }
    if (c == 'C')
    {
      C++;
      if (c1 == 'C' && c2 == 'C' && c3 == 'C')
      {
	return false;
      }
    }
    if (c == 'X')
    {
      X++;
      if (c1 == 'X' && c2 == 'X' && c3 == 'X')
      {
	return false;
      }
    }
    if (c == 'I')
    {
      I++;
      if (c1 == 'I' && c2 == 'I' && c3 == 'I')
      {
	return false;
      }
    }
    
    if (M > 4 || C > 4 || X > 4 || I > 3)
    {
      false;
    }
  }
  return true;
}

/******************
 *validEndStr validates the 
 *ending of the roman number in
 *@param roman[]
 ******************/
bool validEndStr(char roman[])
{
  char c, c1, c2, c3;
  int i;
  for (i = 0; roman[i] != '\0'; i++)
  {
    c = roman[i], c1 = roman[i - 1];
    c2 = roman[i - 2], c3 = roman[i - 3];
    
    if (c2 == 'I' && c1 == 'X' && isalpha(c))
    {
      return false;
    }
    if (c2 == 'I' && c1 == 'V' && isalpha(c))
    {
      return false;
    }
    if (c3 == 'I' && c2 == 'I' && c1  == 'I' &&
	isalpha(c))
    {
      return false;
    }
    if ((c2 == 'I' && c1 == 'I') &&
	(isalpha(c) && c != 'I'))
    {
      return false;
    }
  }
  return true;  
}


/*******************
 *beforeRule returns false
 *if the wrong roman number
 *comes before some other roman 
 *number in the @param roman array
 ******************/
bool beforeRule(char roman[])
{
  char c, c1, c2;
  int i;
  for (i = 0; roman[i] != '\0'; i++)
  {
    c = roman[i], c1 = roman[i - 1], c2 = roman[i - 2];

    if (i > 0)
    {
      if ((c == 'M' || c == 'D') && (c1 != 'M' && c1 != 'C'))
      {
	return false;
      }

      if (c == 'C' || c == 'L')
      {
	if (c1 != 'M' && c1 != 'D' && c1 != 'C' && c1 != 'X')
	{
	  return false;
	}
      }
    }
    if (c == 'V' && c1 == 'V')
    {
      return false;
    }
    if (i >= 2)
    {
      if (c2 != 'M' && c1 == 'C' &&
	  (c == 'M' || c == 'D'))
      {
	return false;
      }
      
      if (c1 == 'X' && (c == 'C' || c == 'L'))
      {
	if (c2 != 'M' && c2 != 'D' && c2 != 'C')
	{
	  return false;
	}
      }
      if ((c1 = 'I') && (c == 'X' || c == 'V'))
      {
	if (c2 != 'M' && c2 != 'D' && c2 != 'C' &&
	    c2 != 'L' && c2 != 'X')
	{
	  return false;
	}
      }
    }   
  }
  return true;
}

/***************
 *AfterRule returns false if 
 *the wrong roman numeral comes
 *after some roman numeral in the
 *@param roman array
 ***************/
bool afterRule(char roman[])
{
  char c, c1, c2;
  int i;
  for (i = 0; roman[i] != '\0'; i++)
  {
    c = roman[i], c1 = roman[i - 1], c2 = roman[i - 2];
    if (c1 == 'D' || c1 == 'X')
    {
      if (c != 'C' && c != 'L'&&
	  c != 'X' && c != 'V'&& c != 'I')
      {
	return false;
      }
    }
    if (c1 == 'L' || c1 == 'I')
    {
      if (c != 'X' && c != 'V' && c != 'I')
      {
	return false;
      }
    }
    if (c1 == 'V' && c != 'I')
    {
      return false;
    }
    if (c2 == 'C' && (c1 == 'M' || c1 == 'D'))
    {
      if (c != 'C' && c != 'L' && c != 'X' &&
	  c != 'V' && c != 'I')
      {
	return false;
      }
    }
    if (c2 == 'X' && (c1 == 'C' || c1 == 'L'))
    {
      if (c != 'X' && c != 'V' && c != 'I')
      {
	return false;
      }
    }
  }
  return true;
}

/*****************
 *exist returns false
 *if a roman number has a wrong
 *arrangement of it's values, thus
 *not a valid roman number
 ****************/
bool exist(char roman[])
{
  if (!validEndStr(roman) || !repeatRule(roman))
  {
    return false;
  }
  if (!beforeRule(roman) || !afterRule(roman))
  {
    return false;
  } 
  return true;
}

/**************
 *reset sets all value of 
 *roman[] to 0
 **************/
void reset(char roman[])
{
  int i;
  for (i = 0; i < 16; i++)
  {
    roman[i] = 0;
  }
}
