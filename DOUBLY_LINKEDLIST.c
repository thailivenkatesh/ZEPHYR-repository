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
   
    while(pos!=1){
		temp1=ptr;
        ptr=ptr->next;
        pos--;
    }
    temp->prev=temp1;
    temp->next=ptr;
    temp1->next=temp;
    ptr->prev=temp;
    return head;
}

struct node* delete_at_start(struct node* head){
    struct node* temp=head;
    head=head->next;
    
    free(temp);
    temp=0;head->prev=0;
    return head;
}
void delete_at_end(struct node* head){
    struct node* ptr=head;
    struct node* temp;
    while(ptr->next!=0){
        temp=ptr;
        ptr=ptr->next;
    }
  temp->next=0;
  free(ptr);
  ptr=0;
}
void delete_at_certain(struct node* head,int pos){
    struct node* ptr=head;
    struct node* temp;
	 struct node* temp1;
	 pos--;
    while(pos!=0){
        temp=ptr;
        ptr=ptr->next;
        pos--;
    }
	temp1=ptr;
	temp1->prev=ptr->prev;
	temp->next=ptr->next;
 
  free(ptr);
  ptr=0;
}

struct node* rev(struct node* head){
    struct node* ptr1=head;
    struct node* ptr2=ptr1->next;
    ptr1->next=0;
    ptr1->prev=ptr2;
   
    while(ptr2!=0){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
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
	head=add_at_certain(head,8,5);
	ptr=head;
	printf("\ncertain : ");
	print(ptr);
        head=delete_at_start(head);
	ptr=head;
	printf("\ndelete 1st : ");
	print(ptr);
	delete_at_end(head);
	ptr=head;
	printf("\ndelete end : ");
	print(ptr);
	delete_at_certain(head,4);
	ptr=head;
	printf("\ndelete certain : ");
	print(ptr);
	head=rev(head);
	ptr=head;
	printf("\nrev  : ");
	print(ptr);
	
	return 0;
}
