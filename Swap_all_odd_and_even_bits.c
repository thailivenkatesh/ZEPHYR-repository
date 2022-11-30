//Swap all odd and even bits
#include <stdio.h>
int main()
{
    int data = 7;
    printf("%d\n",(data & 0xA)>>1);//0111&1010=0010>>1=0001=1
    printf("%d\n",(data & 0x5)<<1);//0111&0101=0101<<1=1010=10
    data = ((data & 0xAA)>>1 | (data & 0x55)<<1);//0001+1010=1011=11
    printf("%d\n",data);
    printf("%d",data);
    return 0;
}
