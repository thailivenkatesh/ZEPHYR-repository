#include <stdio.h>
int main() {
    int n=50,rem,hex=0,base=1;
    while(n>0){
    rem=n%16;
    hex+=rem*base;
    base=base*10;
    n=n/16;
    }
printf("%d",hex);
    return 0;
}