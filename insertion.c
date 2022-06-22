#include <stdio.h>
void insertionsort(int a[],int n){
    int i,hole,value;
    for(i=1;i<n;i++){
   value=a[i];
   hole=i;
   while(hole>0 && a[hole-1]>value)
   {
       a[hole]=a[hole-1];
       hole-=1;
   }
   a[hole]=value;
    }
     for(i=0;i<n;i++)
     printf("%d\t",a[i]);
}
int main() {
 int arr[]={5,4,2,7,3,6,1};
 int size=sizeof(arr)/sizeof(arr[0]);
 insertionsort(arr,size);
 return 0;
}
