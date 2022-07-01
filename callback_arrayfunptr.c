// Online C compiler to run C program online
#include <stdio.h>
void add(int x, int y){
    printf("%d\n",x+y);
}
void sub(int x, int y)
{
  printf("%d",x-y);
}
void p(void(*ptr)(int,int)){
   ptr(6,3);
}


int main() {
 void(*ptr[])(int,int)= {add,sub};
 
    p(ptr[0]);
    p(ptr[1]);
    return 0;
}