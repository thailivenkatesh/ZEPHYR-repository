#include <stdio.h>
int main()
{
    unsigned char value = 0x23; //value in hex
    char x=((value&0x0f)<<4)+((value&0xf0)>>4);
    printf("0x%x", x); //print after swapping
    return 0;
}
