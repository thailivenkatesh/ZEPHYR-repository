#include  <stdio.h>

int main(int argc, const char * argv[])
{
    char name[50],ch;
    int i = 0;
    
 	printf("\n Please Enter any String  : ");
	gets(name);	
	printf("\n Please Enter any Charcater that you want to search for  : ");
	scanf("%c", &ch);
    while (name[i] != '\0')
    {
        
       if(ch==name[i]){
        printf("%s",name+i);
        i++;
        break;
    }i++;
    }
    return 0;
}