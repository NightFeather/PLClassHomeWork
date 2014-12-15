#include <stdio.h>

typedef struct {
  int hour;
  int min;
  int sec;
} time;

time timeminus(time origin,time offset) {

  time result = {0,0,0};
  int buffer = 0;
  buffer = origin.hour * 60 * 60 + origin.min * 60 + origin.sec;
  buffer -= offset.hour * 60 * 60 + offset.min * 60 + offset.sec;
  result.hour = buffer / 3600;
  result.min  = buffer / 60 % 60;
  result.sec  = buffer % 60;
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

#if defined(_WIN32) || defined(_WIN64)
  system("pause");
#endif
  
  return 0;
}
