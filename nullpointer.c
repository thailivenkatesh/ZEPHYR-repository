// Null pointer is a pointer which doesn't point to anymemory location. it represents an invalid memory location

#include <stdio.h>

//int main() {
    // Write C code here
    //unsigned int a=9;
   // int *p=NULL;//when a null value is assigned to a pointer it becomes null pointer
    //return 0;
//}
//it is used to initialise the pointer when that pointer isn't assigned any valid memory address yet
//useful for handling errors
int main(){
    int *ptr;
    ptr=(int*)malloc(sizeof(int));
    if(ptr==NULL)
        printf("memory not allocted");
   else
   printf("memory allocated");

}
