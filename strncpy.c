#include <stdio.h> 
#include<string.h>
int main()
{
   char str1[50];
   char str2[50];
   printf("\n Please enter the String you want to Copy: \n");
   gets(str1);
   int i;
   for(i=0;i<4;i++){
       str2[i]=str1[i];
   }
  str2[i]='\0';
  puts(str2);
}
