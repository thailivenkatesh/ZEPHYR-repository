//program to count set bits in an integer
#include <stdio.h>
int main(int argc, char *argv[])
{
    unsigned char cData=0xff;
    int iPos =0,j=0,i;
    printf("Initially cData = 0x%x\n\n",cData);
    for(i=0;i<8;i++)
    if(cData & (1<<i))   //Check bit set or not
    j++;
    printf("%d",j);
    return 0;
}
