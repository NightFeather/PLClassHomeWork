#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int flag = 4;
	int age = 0;
	printf("輸入年齡: ");

	scanf(" %d",&age);

	if(age >110 || age < 0)
	{
		printf("錯誤: 超出範圍(0~110)\n");
		system("pause");
		return 1;
	}
	if( age >=18 )
		flag = 1;
	else if ( age >= 12 )
	    flag = 2;
	else if ( age >= 6 )
		flag = 3;
	else
	    flag = 4;

	printf("\n可觀看級別: \n");

	switch(flag) {
		case 1:
			printf("限制級\n");
		case 2:
			printf("輔導級\n");
		case 3:
			printf("保護級\n");
		case 4:
			printf("普遍級\n\n");
	}
	return 0;
}
