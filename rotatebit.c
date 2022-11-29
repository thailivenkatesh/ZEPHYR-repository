//program to Rotate bits of a number in C
#include <stdio.h>
int main(int argc, char *argv[])
{
    unsigned char cData=32;
    int iPos =0,j=0,i=2;
    printf("Initially cData = 0x%x\n\n",cData);

    printf("leftshift:%d\n",cData<<i);
    printf("rightshift:%d",cData>>i);
    return 0;
}
