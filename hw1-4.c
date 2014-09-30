#include <stdio.h>
#include <stdlib.h>


int main(void){

  int money = 0, part = 0, delim = 0;

  printf("請輸入金額: ");
  scanf(" %d",&money);

  if(money < 0 || money > 99999)
  {
    printf("輸入金額超出範圍");
    return 0;
  }

  for( delim = 10000;delim >= 1; delim /= 10){

    part = money / delim;

    if(part == 0) { continue; }

    switch( money / delim ) {
      case 1: printf("壹"); break;
      case 2: printf("貳"); break;
      case 3: printf("參"); break;
      case 4: printf("肆"); break;
      case 5: printf("伍"); break;
      case 6: printf("陸"); break;
      case 7: printf("柒"); break;
      case 8: printf("捌"); break;
      case 9: printf("玖"); break;
    }

    switch( delim ) {
      case    10 : printf("拾"); break;
      case   100 : printf("佰"); break;
      case  1000 : printf("仟"); break;
      case 10000 : printf("萬"); break;
    }

    money -= part * delim;
  }
  printf("元整\n");
  return 0;
}

