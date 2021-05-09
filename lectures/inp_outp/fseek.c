#include <stdio.h>


int main(void)
{
    size_t size = 256;
    int beginHere = 7;
    FILE *testfile;
    char buffer[size];
    
    /* open file to write to it */
    testfile = fopen("fseek.txt", "w");
    fprintf(testfile, "Hello world");
    /* fputs("Hello World", testfile); */
    fclose(testfile);

    /* open file to read from it */
    testfile = fopen("fseek.txt", "r");
    fgets(buffer, size, testfile);
    printf("\nOriginal buffer: %s\n", buffer);
    fclose(testfile);

    /* open to change override parts of the file using fseek */
    testfile = fopen("fseek.txt", "a");
    fseek(testfile, 7, SEEK_SET);
    fprintf(testfile, "Overriden using fseek");
    /* fputs("Overriden using fseek", testfile); */
    fclose(testfile);

    /* open to read, to now see the effect of fseek */
    testfile = fopen("fseek.txt", "r");
    fgets(buffer, size, testfile);
    printf("\nAltered buffer: %s\n\n", buffer);
    fclose(testfile);
}
