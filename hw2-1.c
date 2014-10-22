#include <stdio.h>

int main() {
  int score = 0;
  int avg[2] = {0};
  int red[2][3] = {-1};
  int max[2][2] = {0};
  int i = 0, j = 0, flag = 0;

  for( i = 0; i < 2 ; i++){
   for( j = 0; j < 3; j++) {

    do {
     printf("請輸入第%02d班第%02d號的成績: ", i+1 , j+1);
     scanf("%d", &score); 
    
     if( score > 100 || score < 0 ) {
      printf("超出範圍 重新輸入\n");
      flag = !flag;
     }else {
      flag = 0;
     }
    }while(flag);
    
    avg[i] += score;

    if( score < 60) { red[i][j] = score; }

    if( score > max[i][1]) { max[i][0] = j; max[i][1] = score; }
   }
   avg[i] /= 3;
  }

  for( i = 0; i < 2; i++ ) {
   printf("第%2d班\n",i+1);
   printf("平均: %2d 分\n", avg[i]);

   printf("不及格: \n");
   for( j = 0, flag = 0; j < 3; j++) {
    if( red[i][j] > 0){
     flag = 1;
     printf("%2d號: %2d 分\n", j+1, red[i][j]);
    }
   }
   if(!flag) {printf("沒有人不及格\n");}

   printf("最高分: %2d號 %2d 分\n\n", max[i][0],max[i][1] );
  }

  return 0;
}
