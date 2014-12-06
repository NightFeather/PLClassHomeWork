#include <stdio.h>

typedef struct {
  int hour;
  int min;
  int sec;
} TIME;

TIME timeMinus(TIME origin,TIME offset) {
  TIME result = {0,0,0};
  if(origin.sec < offset.sec) {
    origin.min --;
    origin.sec += 60;
  }
  result.sec = origin.sec - offset.sec;
  if(origin.min < offset.min || origin.min < 0) {
    origin.hour --;
    origin.min += 60;
  }
  result.min = origin.min - offset.min;
  result.hour = origin.hour - offset.hour;
  return result;
}

int main() {

  TIME midnight = {23,59,59}, parsing, result;
  int limit[3] = {24,60,60}, offset = sizeof(int), i = 0, input;
  char tags[3][5] = {"Hour","Min","Sec"};
  printf("Type in the time of now\n");
  for(i = 0; i < 3; i++) {
    do {
      printf("%s: ",tags[i]);
      scanf("%d",&input);
    }while(input <0 || input >= limit[i]);
    *((int *)(((char*)&parsing)+offset*i)) = input;
  }
  result = timeMinus(midnight, parsing);
  printf("Remaining: %02d:%02d:%02d\n",result.hour,result.min,result.sec);
  return 0;
}
