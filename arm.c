// arm
#include <stdio.h>
int main() {
    int n=153,rem,arm=0,temp;
    temp=n;
    while(n>0){
    rem=n%10;
    arm+=(rem*rem*rem);
    n=n/10;
    }
    if(temp==arm)
       printf("arm:%d",arm);
    else
       printf("not arm:%d",arm);
    return 0;
}