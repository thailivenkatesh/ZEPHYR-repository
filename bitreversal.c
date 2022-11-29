#include<stdio.h>
//bit reversal function
unsigned int ReverseTheBits(unsigned int n)
{
    unsigned int i= 0;
    unsigned int rev = 0;         //  Assign num to the tmp
    for(; i < 16; ++i)
    {
        if((n & (1 << i))) // check set bits of num
        {
            rev |= 1 << ((16 - 1) - i); //putting the set bits of num in tmp
        }
    }
    return rev;
}
int main(){
   printf("%d", ReverseTheBits(01));
   return 0;
}
