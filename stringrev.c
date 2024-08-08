//  C Programming to rev strings  
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


//using recursion
#include <stdio.h> 
#include<string.h>
void rev()
{
    char ch;
    scanf("%c",&ch);
    if(ch!='\n'){
        rev();
        printf("%c",ch);
        }
}
int main()
{
    printf("original string:");
    rev();
    getchar();
    return 0;
}
