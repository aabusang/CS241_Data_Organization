/*************************
 *By: Adam Abusang
 *A program to read data from stdin and 
 *sort according to directions (by country, team, name) 
 *************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 146
#define COLS 5
#define N 21
#define LINE_LENGTH 130

void printTitles();
void printAll(char arr[ROWS][COLS][N], int c[], int n[]);

void sortByNumbers(char arr[ROWS][COLS][N], int n[]);
void sortByCountries(char arr[ROWS][COLS][N], int class[]);
void top3Times(char arr[ROWS][COLS][N]);

void reset(char arr[]);

int main(int argc, char *argv[])
{
  
  char data[ROWS][COLS][N] = {0};
  char line[LINE_LENGTH];
    
  int class[ROWS - 1], numbers[ROWS - 1];
    
  char name[N], country[N];
  char time[N], team[N];
  
  int i = 0, j = 0, row, col;
  int n = 0, c;

  while(fgets(line, LINE_LENGTH, stdin) != NULL)
  {
    sscanf(line, "%d%s%d%s%s%s", &class[n], name,
	   &numbers[n], country, team, time);
	
    for (row = 0; row < 1; row++)
    {
      for (col = 0; col < 1; col++, j++)
      {
	for (c = 0; name[c] != '\0'; c++)
	{
	  data[i][1][c] = name[c];
	}
	for (c = 0; country[c] != '\0'; c++)
	{
	  data[i][2][c] = country[c];
	}
	for (c = 0; team[c] != '\0'; c++)
	{
	  data[i][3][c] = team[c];
	}
	for (c = 0; time[c] != '\0'; c++)
	{
	  data[i][4][c] = time[c];
	}
      }
    }
    n++, i++;
  }

  printTitles(argv[1]);
    
  if (strcmp(argv[1], "format") == 0)
  {
    printAll(data, class, numbers);
  }
  if (strcmp(argv[1], "team") == 0)
  {
    sortByNumbers(data, numbers);
  }
  if (strcmp(argv[1], "country") == 0)
  {
    sortByCountries(data, class);
  }
  if (strcmp(argv[1], "extra") == 0)
  {
    top3Times(data);
  }
  return 0;
}

void top3Times(char arr[ROWS][COLS][N])
{
  printf("To print top 3 times\n");
    
}

/**************
 *returns nothing
 *prints titles according to argv[1]
 ***********************************/
void printTitles(char argv1[])
{
  char rclass[] = "Classification";
  char rname[] = "Rider";
  char rnumber[] = "Rider No.", rcountry[] = "Country";
  char rteam[] = "Team", rtime[] = "Time (hh:mm:ss)";

  if (strcmp(argv1, "format") == 0)
  {
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n",
	   rclass, rname, rnumber, rcountry, rteam, rtime);
  }
  if (strcmp(argv1, "team") == 0)
  {
    printf("%-20s%-20s%-20s%-20s\n",
	   rteam, rnumber, rname, rtime);
  }
  if (strcmp(argv1, "country") == 0)
  {
    printf("%-20s%-20s%-20s%-20s\n",
	   rcountry, rname, rclass, rtime);
  }
  if (strcmp(argv1, "extra") == 0)
  {
    printf("%-20s%s\n", rteam, rtime);
  }
}


/**********************
 *prints formatted (-20) version ofeverything 
 *read from tdf20.in to data
 *********************/
void printAll(char arr[ROWS][COLS][N], int c[], int n[])
{
  int i = 0, j = 0, k = 0;
  char tmpText[N];
    
  for (i = 0; i < ROWS; i++)
  {
    reset(tmpText);
    for (j = 0; j < COLS; j++)
    {
      if (j == 0)
      {
	printf("%-20d", c[i]);
      }
      if (j == 2)
      {
	printf("%-20d", n[i]);
      }

      for (k = 0; arr[i][j][k] != '\0'; k++)
      {
	tmpText[k] = arr[i][j][k];
      }
      /*so not print destructing -20 spaces*/
      if (j > 0)
      {
	if (j == 4)
	{
	  /*don't do -20 for time*/
	  printf("%s", tmpText);
	}
	else
	{
	  printf("%-20s", tmpText);
	}
	reset(tmpText);
      }

    }
    printf("\n");
  }
}


/************************
 *sort data by numbers and print
 ***********************/
void sortByNumbers(char arr[ROWS][COLS][N], int n[])
{
  int i = 0, j = 0, k = 0;
  char tmpTime[N], tmpTeam[N];
  char tmpName[N], tmpText[N];
    
  for (i = 0; i < ROWS; i++)
  {
    for (j = i + 1; j < ROWS; j++)
    {
      if (n[i] > n[j])
      {
	/*sort the numbers*/
	int tmp = n[i];
	n[i] = n[j];
	n[j] = tmp;

	/*sort lines in data*/
	for (k = 0; k < COLS; k++)
	{
	  /****************
	   *sort if at the indexes of 
	   *name, team and time column
	   ***********/
	  if (k == 1 || k == 3 || k == 4)
	  {
	    strcpy(tmpText, arr[i][k]);
	    strcpy(arr[i][k], arr[j][k]);
	    strcpy(arr[j][k], tmpText);
	  }
	}
      }
    }
  }

  reset(tmpName);
  reset(tmpTeam);
  reset(tmpTime);
  /*read and print sorted data in a formatted way*/
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      /*read from data to tmp variables*/
      if (j == 1)
      {
	for (k = 0; arr[i][j][k] != '\0'; k++)
	{
	  tmpName[k] = arr[i][j][k];
	}
      }
      if (j == 3)
      {
	for (k = 0; arr[i][j][k] != '\0'; k++)
	{
	  tmpTeam[k] = arr[i][j][k];
	}
      }
      if (j == 4)
      {
	for (k = 0; arr[i][j][k] != '\0'; k++)
	{
	  tmpTime[k] = arr[i][j][k];
	}
      }
    }
    /*print name team and time in formatted way*/
    for (j = 0; j < COLS; j++)
    {
      if (j == 0)
      {
	printf("%-20s", tmpTeam);
	reset(tmpTeam);
      }
      if (j == 1)
      {
	printf("%-20d", n[i]);
      }
      if (j == 2)
      {
	printf("%-20s", tmpName);
	reset(tmpName);
      }
      if (j == 3)
      {
	printf("%s", tmpTime);
	reset(tmpTime);
      }
    }
    printf("\n");
  }
}
/******************
 *sort data by countries (+ rider names) and print
 ******************/
void sortByCountries(char arr[ROWS][COLS][N], int class[])
{
  char tmpCountry[N], tmpName[N], tmpTime[N];
  char tmpText[N];
  int tmpNum = 0;
  int i = 0, j = 0, k = 0, s = 0;

  /*sort*/
  for (i = 0; i < ROWS; i++)
  {
    for (j = i + 1; j < ROWS; j++)
    {
      for (k = 0; k < COLS; k++)
      {
	if (k == 2)/*country column*/
	{
	  if (strcmp(arr[i][k], arr[j][k]) > 0)
	  {
	    for (s = 0; s < COLS; s++)
	    {
	      strcpy(tmpText, arr[i][s]);
	      strcpy(arr[i][s], arr[j][s]);
	      strcpy(arr[j][s], tmpText);
	      reset(tmpText);
	    }
	    tmpNum = class[i];
	    class[i] = class[j];
	    class[j] = tmpNum;
	  }
	  /*if countries are same*/
	  if (strcmp(arr[i][k], arr[j][k]) == 0)
	  {
	    /*if first name more lexic  than second*/
	    if (strcmp(arr[i][1], arr[j][1]) > 0)
	    {
	      for (s = 0; s < COLS; s++)
	      {
		strcpy(tmpText, arr[i][s]);
		strcpy(arr[i][s], arr[j][s]);
		strcpy(arr[j][s], tmpText);
		reset(tmpText);
	      }
	      tmpNum = class[i];
	      class[i] = class[j];
	      class[j] = tmpNum;
	    }
	    /*sort by class numbers if countries are 
	     *same and names are same
	     ****************************/
	    if (strcmp(arr[i][1], arr[j][1]) == 0)
	    {
	      if (class[i] > class[j])
	      {
		for (s = 0; s < COLS; s++)
		{
		  strcpy(tmpText, arr[i][s]);
		  strcpy(arr[i][s], arr[j][s]);
		  strcpy(arr[j][s], tmpText);
		  reset(tmpText);
		}
		tmpNum = class[i];
		class[i] = class[j];
		class[j] = tmpNum;	
	      }
	    }
	  }
	}
      }
    }
  }
  reset(tmpName);
  reset(tmpCountry);
  reset(tmpTime);
  /*print out sorted data in formatted way*/
  for (i = 0; i < ROWS; i++)
  {
    /*read from sorted data array*/
    for (j = 0; j < COLS; j++)
    {
      if (j == 1)
      {
	strcpy(tmpName, arr[i][j]);
      }
      if (j == 2)
      {
	strcpy(tmpCountry, arr[i][j]);		
      }
      if (j == 4)
      {
	strcpy(tmpTime, arr[i][j]);		
      }
    }
	
    /*print to stdout*/
    for (j = 0; j < COLS; j++)
    {
      if (j == 0)
      {
	printf("%-20s", tmpCountry);
	reset(tmpCountry);
      }
      if (j == 1)
      {
	printf("%-20s", tmpName);
	reset(tmpName);
      }
      if (j == 2)
      {
	printf("%-20d", class[i]);
      }
      if (j == 3)
      {
	printf("%s", tmpTime);
	reset(tmpTime);
      }
    }
    printf("\n");
  }
}


void reset(char arr[])
{
  int i;
  for (i = 0; i < N; i++)
  {
    arr[i] = 0;
  }
}
