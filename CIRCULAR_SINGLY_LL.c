#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node* next;
};

struct node* add_at_begin(struct node* tail, int data)
{
struct node* newP = malloc(sizeof(struct node));
newP->data = data;
newP->next = tail->next;
tail->next = newP;

return tail;
}
struct node* add_at_end(struct node* tail, int data)
{
struct node* newP = malloc(sizeof(struct node));
newP->data = data;
newP->next = tail->next;
tail->next = newP;
tail=tail->next;
return tail;
}
void add_at_certain(struct node* tail, int data,int pos){
    
struct node* newP = malloc(sizeof(struct node));
newP->data = data;
newP->next = 0;
struct node* temp;
temp=tail->next;
pos--;
while(pos!=1){
    temp=temp->next;
    pos--;
}
newP->next =temp->next;
temp->next=newP;
//return tail;
}
void print(struct node* tail)
{
struct node* p = tail->next;
do
{
printf("%d ", p->data);
p = p->next;
} while(p!=tail->next);
}
int main()
{
    struct node* tail;
    tail= malloc(sizeof(struct node));
    tail->data=1;
    tail->next=tail;
    int i;
    printf("\nbegin:");
    for(i=2;i<7;i++)
    tail=add_at_begin(tail,i);
    print(tail);
    tail=add_at_end(tail,0);
    printf("\nend:");
    print(tail);
    add_at_certain(tail,9,5);
    printf("\ncertain:");
    print(tail);
return 0;
}
