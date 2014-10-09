#include <stdio.h>
#include <stdlib.h>

int main(void){

  float left = 0.0, right = 0.0, result = 0.0;
  int flag = 0, i = 0;
  char op = 0;

  printf( "請輸入兩個數字: " );
  scanf( " %f %f", &left, &right );
  if( right == 0.0 ) { flag = 1; }

  printf( "\n計算結果:\n" );
  for( i = 0; i < 4; i++ )
    {
      switch( i ){
        case 0:
          result = left + right;
          op = '+';
          break;
        case 1:
          result = left - right;
          op = '-';
          break;
        case 2:
          result = left * right;
          op = '*';
          break;
        case 3:
          if( flag ){
            printf("除數不得為零!!!");
            continue;
          }
          else{
            result = left / right;
            op = '/';
            break;
          }
      }

      printf( "%.2f %c %.2f = %.2f\n", left, op, right, result);
  }
  printf("\n");

  return 0;
}
