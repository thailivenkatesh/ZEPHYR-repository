#include<stdio.h>
#include<string.h>
#define NUM 3
int main(){
    char str[50][50]={"hello","world","embedded"};
    int i,j;
    char temp[50];
    for(i=0;i<NUM;i++){
        for(j=i+1;j<NUM;j++){
            if(strcmp(str[i],str[j])>0)
            {
              strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    for(i=0;i<NUM;i++)
    puts(str[i]);
    
}
