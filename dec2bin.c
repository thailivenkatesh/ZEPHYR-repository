// decimal to binary
#include <stdio.h>
int main() {
    int n=10,rem,bin=0,base=1;
    while(n>0){
    rem=n%2;
    bin+=rem*base;
    base=base*10;
    n=n/2;
    }
printf("%d",bin);
    return 0;
}