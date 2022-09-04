// Void pointer is a pointer which has no associated data type with it. it can point to any data type and can be type casted to any type
#include <stdio.h>

int main() {
    // Write C code here
    unsigned int a=9;
    void *p=&a;
    printf("%d",*(int*)p);
    return 0;
}
