// strcat in C Programming to concatenate strings  
#include <stdio.h> 
#include<string.h>
int main()
{
   char str1[] = "Learn";
   char str2[] = " C Lang";

   /*	printf("lib fun\n");
   strcat(str1, str2);		
   puts(str1);*/
   int i,j=0;
   printf("\nown fun\n");
   j=strlen(str1);
   for(i=0;str2[i]!='\0';i++){
      str1[j++]=str2[i];
      }
   str1[j]='\0';
   puts(str1);
}
