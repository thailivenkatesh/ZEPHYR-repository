// Online C compiler to run C program online
#include <stdio.h>
struct node{
    struct node* prev;
    unsigned int data;
    struct node* next;
};
struct node* add_at_end(struct node* head,unsigned int data){
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=0;
    temp->next=0;
     struct node* ptr=head;
    while(ptr->next!=0){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    
    return head;
}
struct node* add_at_begin(struct node* head,unsigned int data){
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=0;
    temp->next=0;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node* add_at_certain(struct node* head,unsigned int data,int pos){
    struct node* temp;
	struct node* temp1;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=0;
    temp->next=0;
     struct node* ptr=head;
     pos--;
    while(pos!=1){
		temp1=ptr;
        ptr=ptr->next;
        pos--;
    }
    temp->prev=ptr;
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
}
void print(struct node *ptr)
{
     while(ptr!=0)
   {
       printf("%d\t",ptr->data);
       ptr=ptr->next;
   }
}
int main() {
    // Write C code here
	struct node* head;
	struct node* ptr;
	head=malloc(sizeof(struct node));
	head->data=4;
	head->prev=0;
	head->next=0;
	head=add_at_begin(head,3);
	head=add_at_begin(head,2);
	head=add_at_begin(head,1);
	ptr=head;
	printf("\nstart : ");
	print(ptr);
	head=add_at_end(head,5);
	head=add_at_end(head,6);
	head=add_at_end(head,7);
	ptr=head;
	printf("\nend : ");
	print(ptr);
	head=add_at_certain(head,8,3);
	ptr=head;
	printf("\certain : ");
	print(ptr);

	return 0;
}