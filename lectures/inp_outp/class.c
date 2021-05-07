#include <stdio.h>

int main(void)
{
    FILE *filePtr;
    size_t size = 256;
    char buffer[size];
    /*will create test.txt if it doesn't exist already and open to be written to*/
    filePtr = fopen("test.txt", "w");
    
    fprintf(filePtr, "Testing file I/O: fprintf\n");
    fputs("Testing fputs...\n", filePtr);

    fclose(filePtr);

    /*Open test.txt to read from it*/
    filePtr = fopen("test.txt", "r");
    fscanf(filePtr, "%s", buffer); /*buffer will be "Testing" here*/
    printf("(a) %s\n", buffer);

    fgets(buffer, size, filePtr);
    printf("(b) %s\n", buffer);

    fgets(buffer, size, filePtr);
    printf("(c) %s\n", buffer);
    
    fseek(filePtr, 100, SEEK_CUR);

    printf("ftell: %ld\n", ftell(filePtr));
    fclose(filePtr);

    /* open to append */
    filePtr = fopen("test.txt", "a");
    fputs("Added more text here\n", filePtr);
    fclose(filePtr);

    
    return 0;
}
