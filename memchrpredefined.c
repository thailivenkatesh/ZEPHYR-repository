//The C memchr function is a String Function, which will find the first occurrence of the character, and returns the pointer to it.
##include <stdio.h> 
#include<string.h>

int main()
{  
   	char str[] = "C Programming Language";
   	char ch = 'L';
   	char *result;
   	char *result2;
   	printf("lib fun\n");
   	result = memchr(str, ch, strlen(str));
   	printf("%s",result);
   	int i;
   	printf("\nown fun\n");
   	for(i=0;str[i]!='\0';i++){
   	    if(str[i]==ch){
   	    printf("%s",str+i);
   	    break;
   	    }
   	}
   	return 0;
} 
