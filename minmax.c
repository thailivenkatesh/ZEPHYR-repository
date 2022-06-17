// Online C compiler to run C program online
#include <stdio.h>
 unsigned char bmsOCVmap(float x, unsigned char in_min, unsigned char in_max, unsigned char out_min, unsigned char out_max)
 {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 }
int main() {
   float bat_vol=53.6;
   unsigned char soc= bmsOCVmap(bat_vol,30,54,0,100);
   printf("%d",soc);
   
    return 0;
}