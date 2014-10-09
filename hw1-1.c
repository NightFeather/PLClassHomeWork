#include <stdio.h>
#include <stdlib.h>

int main(void){

	float left = 0.0, right = 0.0;
        int flag = 0, i = 0;

	printf( "請輸入兩個數字: " );
	scanf( " %f %f", &left, &right );
        if( right == 0.0 ) { flag = 1; }

	printf( "\n計算結果:\n" );
	for( i = 0; i < 4; i++ )
	{
                if( !flag ){
 		 printf( "%.2f + %.2f = ", left, right);
                }

		switch( i ){
		case 0:
			printf("%.2f", left + right);
			break;
		case 1:
			printf("%.2f", left - right);
			break;
		case 2:
			printf("%.2f", left * right);
			break;
		case 3:
			if( flag )
			 { printf("除數不得為零!!!"); }
			else
			 { printf("%.2f", left / right); }
			break;
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
