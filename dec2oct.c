// decimal to binary
#include <stdio.h>
int main() {
    int n=50,rem,oct=0,base=1;
    while(n>0){
    rem=n%8;
    oct+=rem*base;
    base=base*10;
    n=n/8;
    }
printf("%d",oct);
    return 0;
}