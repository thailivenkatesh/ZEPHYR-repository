#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_begin(struct node* head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}

struct node* reverseprint(struct node* ptr)
{
  struct node* prev=0;
   struct node* next=0;
  while(ptr!=0)
  {
      next=ptr->link;
      ptr->link=prev;
      prev=ptr;
      ptr=next;
  }
  ptr=prev;
  
  return ptr;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
    ptr->link=0;
    head->link=ptr;
     
    int data=3;
    head=add_at_begin(head,data);
    int data1=5;
    head=add_at_begin(head,data1);
    
    ptr=head;
   
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
   head=(struct node *)reverseprint(head);
   struct node *ptr1;
      ptr1=head;
     printf("\nrevlist\n");
   
    while(ptr1!=0)
    {
        printf("%d\t",ptr1->data);
        ptr1=ptr1->link;
    }

    return 0;
}





#include <stdio.h>
#include <stdlib.h>
struct node
{
    unsigned int data;
    struct node *link;
};
void print(struct node *ptr)
{
     while(ptr!=0)
   {
       printf("%d\t",ptr->data);
       ptr=ptr->link;
   }
}
insert_certain(struct node* head,unsigned int data,unsigned int pos)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    struct node *ptr=head;
    if(pos==1)
    {
     temp->link=ptr;
     ptr=temp; 
     print(ptr);
    }
    else
    {
    while(pos!=2)
    {
        pos--;
        ptr=ptr->link;
    }
  temp->link=ptr->link;
  ptr->link=temp;
  print(ptr);
    }
}
void insert_end(struct node* head,unsigned int data) 
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    struct node *ptr=head;
    while(ptr->link!=0)
    ptr=ptr->link;
    ptr->link=temp;
}
struct node* insert_begin(struct node*ptr,unsigned int data) 
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    temp->link=ptr;
    ptr=temp;
    return ptr;
}
int main()
{
   struct node *head=malloc(sizeof(struct node));
   head->data=2;
   head->link=0;
   struct node *current=malloc(sizeof(struct node));
   current->data=22;
   current->link=0;
   head->link=current;
   struct node *ptr=head;
   print(ptr);
   printf("\nData after insert at begin\n");
   head=insert_begin(head,3);
   head=insert_begin(head,31);
   ptr=head;
   print(ptr);
   printf("\nData after insert at end\n");
   struct node * ptr1=head;
   insert_end(ptr1,4);
   insert_end(ptr1,41);
   ptr=head;
   print(ptr);
   printf("\nData after certaind\n");
   int data=5,pos=1;
   insert_certain(head,data,pos);
   return 0;
}



//add at end
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node add_at_end(struct node *ptr,unsigned int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    while(ptr->link!=0)
    ptr=ptr->link;
    ptr->link=temp;
    //return temp;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
    struct node *ptr=head;
    add_at_end(ptr,98);
    add_at_end(ptr,99);
    add_at_end(ptr,98);
    add_at_end(ptr,99);
    ptr=head;
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}

//add at begin
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node add_at_begin(struct node head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
     struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
     ptr->link=0;
     head->link=ptr;
     
    int data=3;
   head=add_at_begin(head,data);
      int data1=5;
   head=add_at_begin(head,data1);
    
    ptr=head;
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}
//add at certain
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node add_at_begin(struct node head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}
void add_at_pos(struct node *head ,int pos,int data)
{
    struct node *ptr=head; 
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
     struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
     ptr->link=0;
     head->link=ptr;
     
    int data=3;
   head=add_at_begin(head,data);
      int data1=5;
   head=add_at_begin(head,data1);
   int data2=15;
    int pos=3;
    add_at_pos(head,pos,data2);
    
    ptr=head;
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}



//rev
#include <stdio.h>
#include<stdlib.h>
struct node
{
     int data;
    struct node *link;
};
struct node add_at_begin(struct node head, int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=0;
    ptr->link=head;
    head=ptr;
    return head;
}

struct node reverseprint(struct node ptr)
{
  struct node* prev=0;
   struct node* next=0;
  while(ptr!=0)
  {
      next=ptr->link;
      ptr->link=prev;
      prev=ptr;
      ptr=next;
  }
  ptr=prev;
  
  return ptr;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=0;
     struct node *ptr=malloc(sizeof(struct node));
    ptr->data=46;
     ptr->link=0;
     head->link=ptr;
     
    int data=3;
   head=add_at_begin(head,data);
      int data1=5;
   head=add_at_begin(head,data1);
    
    ptr=head;
   
    while(ptr!=0)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
   head=(struct node *)reverseprint(head);
   struct node *ptr1;
      ptr1=head;
     printf("\nrevlist\n");
   
    while(ptr1!=0)
    {
        printf("%d\t",ptr1->data);
        ptr1=ptr1->link;
    }

    return 0;
}

//all in one


#include <stdio.h>
#include <stdlib.h>
struct node
{
    unsigned int data;
    struct node *link;
};
void print(struct node *ptr)
{
     while(ptr!=0)
   {
       printf("%d\t",ptr->data);
       ptr=ptr->link;
   }
}
insert_certain(struct node* head,unsigned int data,unsigned int pos)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    struct node *ptr=head;
    if(pos==1)
    {
     temp->link=ptr;
     ptr=temp; 
     print(ptr);
    }
    else
    {
    while(pos!=2)
    {
        pos--;
        ptr=ptr->link;
    }
  temp->link=ptr->link;
  ptr->link=temp;
  print(ptr);
    }
}
void insert_end(struct node* head,unsigned int data) 
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    struct node *ptr=head;
    while(ptr->link!=0)
    ptr=ptr->link;
    ptr->link=temp;
}
struct node* insert_begin(struct node*ptr,unsigned int data) 
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=0;
    temp->link=ptr;
    ptr=temp;
    return ptr;
}
int main()
{
   struct node *head=malloc(sizeof(struct node));
   head->data=2;
   head->link=0;
   struct node *current=malloc(sizeof(struct node));
   current->data=22;
   current->link=0;
   head->link=current;
   struct node *ptr=head;
   print(ptr);
   printf("\nData after insert at begin\n");
   head=insert_begin(head,3);
   head=insert_begin(head,31);
   ptr=head;
   print(ptr);
   printf("\nData after insert at end\n");
   struct node * ptr1=head;
   insert_end(ptr1,4);
   insert_end(ptr1,41);
   ptr=head;
   print(ptr);
   printf("\nData after certaind\n");
   int data=5,pos=1;
   insert_certain(head,data,pos);
   return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    printf("%d\n", head->data);
    struct node current = (struct node )malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    printf("%d\n", current->data);
    head->link = current; // link the first node with the second node
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current; //link the second node with the third node
    printf("%d\n", current->data, current);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("the list has %d nodes", count);
}
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    printf("the value head->data is = %d\n", head->data);
    struct node current = (struct node )malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    printf("the value current->data is = %d\n", current->data);
    head->link = current; 
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current; 
    printf("the value current->data is = %d\n", current->data);
    count_of_nodes(head);
    return 0;
}
/ Merge sort in C /
#include<stdio.h>
#include<stdlib.h>

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int A,int L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];

	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) {
	int mid,i, L, R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}

int main() {
	/ Code to test the MergeSort function. /
	
	int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers. 
	int i,numberOfElements;

	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g  
	numberOfElements = sizeof(A)/sizeof(A[0]); 

	// Calling merge sort to sort the array. 
	MergeSort(A,numberOfElements);

	//printing all elements in the array once its sorted.
	printf("\n");
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}

/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
// Two glboal variables to store address of front and rear nodes. 
struct Node* front = NULL;
struct Node* rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
	struct Node* temp = 
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct Node* temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

 void Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("%d",front->data);
}

void Print() {
	struct Node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	/ Drive code to test the implementation. /
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
	Front(); 
}