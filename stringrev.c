// strcat in C Programming to rev strings  
#include <stdio.h> 
#include<string.h>
int main()
{
char str1[5] = "olleh";
char start=0;
char end=(strlen(str1))-1;
while(start<end){
  str1[start]^=str1[end];
  str1[end]^=str1[start];
  str1[start]^=str1[end];
  start++;
  end--;
}
puts(str1);
}
