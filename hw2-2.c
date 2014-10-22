#include <stdio.h>

int main() {

 int arrayA[3][3] = {0};
 int arrayB[3][3] = {0};
 int result[3][3] = {0};
 int i = 0, j = 0;

 for( i = 0; i < 3; i++ ) {
  for( j = 0; j < 3; j++ ) {
   printf("輸入陣列A 元素 %d-%d : ", i, j);
   scanf(" %d", &arrayA[i][j]);
  }
 }
 for( i = 0; i < 3; i++ ) {
  for( j = 0; j < 3; j++ ) {
   printf("輸入陣列B 元素 %d-%d : ", i, j);
   scanf(" %d", &arrayB[i][j]);
   result[i][j] = arrayA[i][j] + arrayB[i][j];
  }
 }
 for( i = 0; i < 3; i++ ) {
  printf("[");
  for( j = 0; j < 3; j++ ) {
   printf(" %2d,", result[i][j]);
  }
  printf("\b ]\n");
 }


 return 0;
}
