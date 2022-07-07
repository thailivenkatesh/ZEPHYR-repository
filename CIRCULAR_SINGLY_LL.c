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
    for(i=2;i<7;i++)
        tail=add_at_begin(tail,i);
    print(tail);

return 0;
}
