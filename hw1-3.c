#include <stdio.h>

int main(void) {

	int side = 0;
	int i = 0, j = 0;

	printf("輸入邊長: ");
	scanf(" %d",&side);
	for(i = side; i > 0; i--) {
	 for(j = side; j > 0; j-- ){
          if( (i % 2) == (j % 2) ) printf("O");
	  else printf("X");
         }
	 printf("\n");
	}

	printf("\n");

	return 0;
}
