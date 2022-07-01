//A callback function is a function passed into another function as an argument, which is then invoked inside the outer function to complete some kind of routine or action
#include<stdio.h>
void add()
{
printf("hello");
}
void b(void(*ptr)())
{
	ptr();
}



int main()
{

//void(*ptr)()=add;
void(*ptr)()=add;
b(ptr);
//ptr();
}
/*
// funptr,array of fun ptr,call back
#include<stdio.h>
void add()
{
printf("add\n");
}
void sub()
{
printf("sub\n");
}
void b(void (*ptr)())
{
    ptr();
}
int main()
{
void (*ptr[])()={add,sub};
ptr[0]();
ptr[1]();
b(ptr[0]);
b(ptr[1]);
}
*/