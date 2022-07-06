// Online C compiler to run C program online
#include <stdio.h>
struct node{
    unsigned int data;
    struct node* link;
};
struct node* add_at_begin(struct node* head,unsigned int data){
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=head;
    head=temp;
    return head;
}
void add_at_end(struct node* head,unsigned int data){
    struct node* temp;struct node* ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    while(ptr->link!=0)
     ptr=ptr->link;
    ptr->link=temp;

}
void add_at_certain(struct node* head,unsigned int data,int pos){
    struct node* temp;struct node* ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    pos--;
    while(pos!=1){
     ptr=ptr->link;
     pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;

}
struct node* rev(struct node* head){
    struct node* ptr=head;
    struct node* next=0;
    struct node* prev=0;
    
    while(ptr!=0){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    ptr=prev;
    return ptr;
}

struct node* delete_at_first(struct node* head){
   struct node* temp;
   temp=head;
   head=temp->link;
   free(temp);
   return head;
}

struct node* delete_at_end(struct node* head){
   struct node* temp;
   struct node* ptr=head;
   while(ptr->link!=0){
	   temp=ptr;
	   ptr=ptr->link;
   }
   
   temp->link=0;
   free(ptr);
   return head;
}
struct node* delete_at_certain(struct node* head,int pos){
   struct node* temp;
   struct node* ptr=head;
   pos--;
   while(pos!=0){
       pos--;
	   temp=ptr;
	   ptr=ptr->link;
   }
   temp->link=ptr->link;
   free(ptr);
   return head;
}
void print(struct node *ptr)
{
     while(ptr!=0)
   {
       printf("%d\t",ptr->data);
       ptr=ptr->link;
   }
}
int main() {
    // Write C code here
struct node* head;
head=malloc(sizeof(struct node));
head->data=4;
head->link=0;
head=add_at_begin(head,3);
head=add_at_begin(head,2);
head=add_at_begin(head,1);
struct node* ptr;
ptr=head;
printf("list : ");
   print(ptr);

printf("\nlast list : ");
add_at_end(head,5);
ptr=head;
   print(ptr);
printf("\ncertain list : ");
add_at_certain(head,6,3);
ptr=head;
   print(ptr);
printf("\nreverse list : ");
head=rev(head);
ptr=head;

   print(ptr);
head=delete_at_first(head);
printf("\ndelete start : ");
ptr=head;

   print(ptr);
printf("\ndelete end : ");
head=delete_at_end(head);
ptr=head;
   print(ptr);
printf("\ndelete certain : ");
head=delete_at_certain(head,2);
ptr=head;
   print(ptr);
    return 0;
}
