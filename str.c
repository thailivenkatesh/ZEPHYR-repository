//own atoi fun
#include <stdio.h>
int main()
{
    char str[]="12345";
    int i,val;
    for(i=0;str[i]!='\0';i++){
       val =val*10+str[i]-48;
    }
    printf("%d",val);
    return 0;
}

//word reverse
#include <stdio.h>
#include<string.h>
int main()
{
    char str[]="hello world emb";
    int i;
    int len=strlen(str);
    for(i=len-1;i>0;i--){
        
        if(str[i]==' '){
            str[i]='\0';
            printf("%s ",&(str[i])+1);
        }
    }
    printf("%s",str);
    return 0;
}
//strtok
#include <stdio.h>
#include<string.h>
int main()
{
    char str[]="hello world emb";
    int i;
    int len=strlen(str);
   char* res;
   res=strtok(str," ");
   while(res!=NULL){
       printf("%s\n",res);
       res=strtok(NULL," ");
   }
    return 0;
}
//polindrome
#include <stdio.h>
#include<string.h>
int main()
{
    char str[]="heluloh";
    int i;
    int cnt =0;
    int len=strlen(str);
  for(i=0;i<len/2;i++){
      if(str[i]==str[len-i-1])
      cnt++;
  }
  if(cnt==0)
  printf("not polondrome");
  else
  printf("polindrome");
    return 0;
}

//one string is rotation of other
#include <stdio.h>
#include<string.h>
int main()
{
    char str[10]="ABCD";
    char str1[10]="CDA";
    char temp[10];
    int i;
    strcat(temp,str);
    strcat(temp,str);
    char *res= strstr(temp,str1);
    printf("%s\n",res);
    if(res!=NULL)
    printf("strings are rotational");
    else
    printf("strings are not rotational");
    return 0;
}
//remove spaces
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100]="heello world";
    int i, j, k;
    
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i]==' '){
            for(; str[i] != '\0'; i++)
            {
                str[i] = str[i + 1];
                }
            }
    }
    printf("%s ", str);
    
    return 0;
}
//freq of each character in a given string
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100]="heallo world";
    int i, j, k;
    int freq[26]={0};
    
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i]>='a'&& str[i]<= 'z'){
          freq[str[i]-'a']++; 
        }
        
    }
    for(i=0;i<26;i++)
    printf("%c %d\n ", i+'a',freq[i]);
    return 0;
}

//string rev using recursion
#include <stdio.h>
#include <string.h>
void rev(char* str){
    
    if(*str){
        rev(str+1);
        printf("%c",*str);
    }
}
int main()
{
    char str[100]="hello";
    rev(str);
    return 0;
}

//sort names in alphabetical order
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50][50]={"ypple","kiwi","orange"};
    char temp[50];
    int i,j;
    int n=3;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(str[i],str[j])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    for(i=0;i<n;i++)
    puts(str[i]);
    return 0;
}
