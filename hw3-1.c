#include <stdio.h>

typedef struct {
  int hour;
  int min;
  int sec;
} time;

time timeminus(time origin,time offset) {

  time result = {0,0,0};

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

  time midnight = {24,0,0}, ship;
  int limit[3] = {24,60,60}, i = 0, input;
  int* pShip[3] = { &(ship.hour),&(ship.min),&(ship.sec) };
  char tags[3][5] = {"Hour","Min","Sec"};

  printf("Type in the time of now\n");
  for(i = 0; i < 3; i++) {
    do {
      printf("%s: ",tags[i]);
      scanf("%d",&input);
    }while(input <0 || input >= limit[i]);
    *pShip[i] = input;
  }

  ship = timeminus(midnight, ship);

  printf("Remaining: %02d:%02d:%02d\n",ship.hour,ship.min,ship.sec);

  return 0;
}
