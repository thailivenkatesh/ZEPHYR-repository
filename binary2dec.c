// binary to decimal
#include <stdio.h>
int main() {
    int n=1010,rem,dec=0,base=1;
    while(n>0){
    rem=n%10;
    dec+=rem*base;
    base=base*2;
    n=n/10;
    }
printf("%d",dec);
    return 0;
}