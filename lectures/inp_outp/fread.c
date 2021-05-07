#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *source = argv[1];
    fread(buffer, sizeOfItem, numOfItems, source);
    fwrite(buffer, sizeOfItem, numOfItems, destination);

}
