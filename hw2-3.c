#include <stdio.h>

int main() {
 int items[10] = {0};
 int i = 0;
 int max[2] = { 0 };
 int min[2] = { 0 };

 printf("輸入十個整數\n");
 for( i = 0; i < 10; i++ ) {
  printf("%2d> ", i+1 );
  scanf(" %d", &items[i]);

  if( i == 0 ) { min[1] = items[i];}

  if(items[i] > max[1]) {
   max[1] = items[i];
   max[0] = i;
  }

  if(items[i] <= min[1]) {
   min[1] = items[i];
   min[0] = i;
  }
 }

 printf("Max:\t%d: %d\n",max[0],max[1]);
 printf("Min:\t%d: %d\n",min[0],min[1]);

 return 0;
}
