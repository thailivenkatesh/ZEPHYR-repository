// Online C compiler to run C program online
#include <stdio.h>
void selectionsort(int a[],int n){
    int imin,i,j,temp;
    for(i=0;i<n-1;i++){
        imin=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[imin]){
            imin=j;
        }}
        
        temp=a[i];
        a[i]=a[imin];
        a[imin]=temp;
    }
     for(i=0;i<n;i++)
     printf("%d\t",a[i]);
}

int main() {
 int arr[]={2,7,4,1,3,6,5};
 int size=sizeof(arr)/sizeof(arr[0]);
 selectionsort(arr,size);
 return 0;
}