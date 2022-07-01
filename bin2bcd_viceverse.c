//bcd2bin viceversa
#include<stdio.h>
 int bcd_to_binary( int value){
    int m,n;
    m=(int)((value>>4)* 10);
    n=value & (int)0X0F;
 return m+n;
}
int binary_to_bcd( int value){
    int m,n;
    int bcd=0;
    if(value >=10) {
        m=value/10;
        n=value%10;
        bcd=( int) ((m<<4) | n) ;
	  }
 return bcd;
}
int main(){
 int temp= binary_to_bcd(14);
 printf("%d\n",temp);
 temp= bcd_to_binary(20);
 printf("%d",temp);
 return 0;
}