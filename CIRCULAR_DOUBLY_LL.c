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
void addAtcertain(struct node* tail, int data,int pos){
    
    struct node* newP =  malloc(sizeof(struct node));
    newP->prev = newP;
    newP->data = data;
    newP->next = newP;
    pos--;
    struct node* temp;
    struct node* ptr=tail->next;
    while(pos!=0){
        temp=ptr;
        ptr=ptr->next;
        pos--;
        
    }
    
    newP->next = ptr->prev;
    newP->prev = temp->next;
    temp->next = newP;
    ptr->prev = newP;

}
struct node* addAtfirst(struct node*tail){
    struct node* temp=tail->next;
    struct node* ptr=temp->next;
    ptr->prev = tail;
    tail->next=ptr;
    free(temp);
    temp=0;
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
	printf("\ncertain:");
	addAtcertain(tail, 67,4);
	print(tail);

	printf("\ndelete 1st:");
	tail=addAtfirst(tail);
	print(tail);
return 0;
}
