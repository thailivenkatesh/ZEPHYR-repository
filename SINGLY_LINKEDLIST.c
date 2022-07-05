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
while(ptr!=0){
    printf("%d\t",ptr->data);
    ptr=ptr->link;
}

printf("\nlast list : ");
add_at_end(head,5);
ptr=head;
while(ptr!=0){
    printf("%d\t",ptr->data);
    ptr=ptr->link;
}
printf("\ncertain list : ");
add_at_certain(head,6,3);
ptr=head;
while(ptr!=0){
    printf("%d\t",ptr->data);
    ptr=ptr->link;
}
printf("\nreverse list : ");
head=rev(head);
ptr=head;

while(ptr!=0){
    printf("%d\t",ptr->data);
    ptr=ptr->link;
}
head=delete_at_first(head);
printf("\ndelete list : ");
ptr=head;

while(ptr!=0){
    printf("%d\t",ptr->data);
    ptr=ptr->link;
}
    return 0;
}