
#include<stdio.h>
// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int *a,int start, int end){
	int pivot=a[end];
	int partition_index=start;//set partition index as start initially
	int i;
	for(i=start;i<end;i++){
		if(a[i]<=pivot){
			swap(&a[i],&a[partition_index]);
		
		   partition_index++;
		} 
	} 
	
	swap(&a[partition_index],&a[end]);    	   
    return partition_index;
}

void quicksort(int *a, int start ,int end){
	if(start<end){
		int partition_index=partition(a,start,end);//calling partiotion
		quicksort(a,start,partition_index-1);
		quicksort(a,partition_index+1,end);
	}
}
int main(){
	int a[]={7,2,3,1,5,6,4};
	quicksort(a,0,6);
	int i;
	for(i=0;i<7;i++)
		printf("%d\t",a[i]);
}
		