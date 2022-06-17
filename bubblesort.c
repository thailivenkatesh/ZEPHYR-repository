#include <stdio.h>
void bubblesort(int a[],int n){
    int imin,i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
     for(i=0;i<n;i++)
     printf("%d\t",a[i]);
}
int main() {
 int arr[]={5,4,2,7,3,6,1};
 int size=sizeof(arr)/sizeof(arr[0]);
 bubblesort(arr,size);
 return 0;
}