#include <stdio.h>

#define NUM_KEYWORDS 10
//parallel arrays
char *keyword[NUM_KEYWORDS];
int keycount[NUM_KEYWORDS];

//array of structures
struct keyStructure
{
    char *word; //allocate memory for a char pointer
    int count;
}key[NUM_KEYWORDS];

int main(void)
{
    key[0].word = "if";
    key[1].word = "for";

    key[2].word = "char";
    key[3].word = "int";

    for (int i = 0; i < 4; i++)
    {
	printf("%s\n", key[i].word);
    }
}
