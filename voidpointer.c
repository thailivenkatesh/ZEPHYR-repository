// Void pointer is a pointer which has no associated data type with it. it can point to any data type and can be type casted to any type
#include <stdio.h>

int main() {
    // Write C code here
    unsigned int a=9;
    void *p=&a;//pointing to int type data type
    printf("%d",*(int*)p);//type casted and dereferenced
    // printf("%d",*p);//output error//we cannot dereference a void pointer
    return 0;
}
