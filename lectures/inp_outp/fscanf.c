#include <stdio.h>

#define MAX 10

int main(int argc, char *argv[])
{
    FILE *inputFile;
    
    char name[MAX];
    int age;
    char school[MAX];
    char country[MAX];
    char job[MAX];
    
    if (argc != 2)
    {
	printf("Usage: ./fscanf input_file\n");
	return 1;
    }
    inputFile = fopen(argv[1], "r");

    fscanf(inputFile, "%s%d%s%s%s", name, &age, school, country, job);
    printf("Name: %s\nAge: %d\nSchool: %s\nCountry: %s\nJob: %s\n",
	   name, age, school, country, job);
    
    
    return 0;
}
