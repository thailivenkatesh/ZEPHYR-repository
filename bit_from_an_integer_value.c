#include <stdio.h>

int main()
{
    unsigned char value = 16; //value in hex 00010000
    unsigned char position = 1;
    printf("%d\n", (value&(1<<position))>>position); //print gets value from the 1th position
    position = 4;
    printf("%d\n", (value&(1<<position))>>position); //print gets value from the 1th position
    return 0;
}
