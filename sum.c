// sum
#include <stdio.h>
int main() {
    int n=123,sum=0,rem;
    while(n>0){
    rem=n%10;
    sum+=rem;
    n=n/10;
    }
       printf("sum:%d",sum);
return 0;
}