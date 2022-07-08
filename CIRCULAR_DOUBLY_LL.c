#include <stdio.h>
#include <stdlib.h>
struct node
{
struct node* prev;
int data;
struct node *next;
};

struct node* addAtBeg(struct node* tail, int data){
    
struct node* newP =  malloc(sizeof(struct node));
newP->prev = newP;
newP->data = data;
newP->next = newP;

newP->prev = tail->next;
newP->next = tail->next;
tail->prev = newP;
tail->next = newP;

}

struct node* addAtend(struct node* tail, int data){
    
struct node* newP =  malloc(sizeof(struct node));
newP->prev = newP;
newP->data = data;
newP->next = newP;

newP->next = tail->next;
newP->prev = tail;
tail->next = newP;
tail = newP;
return tail;
}


void print(struct node* tail){

struct node* temp = tail->next;
do
{
printf("%d ", temp->data);
temp = temp->next;
} while(temp != tail->next);

printf("\n");
}
int main()
{
    struct node* tail = NULL;
    tail=malloc(sizeof(struct node));
    tail->data=35;
    tail->prev=tail;
    tail->next=tail;
	printf("\nbegin:");
    tail = addAtBeg(tail, 34);tail = addAtBeg(tail, 32);tail = addAtBeg(tail, 31);tail = addAtBeg(tail, 30);
    print(tail);
	printf("\nend:");
	tail = addAtend(tail, 36);tail = addAtend(tail, 37);
	print(tail);
return 0;
}
