#include <stdio.h>

int main() {
  int hour, minute, second, time;
  scanf("%d %d %d", &hour, &minute, &second);
  scanf("%d", &time);
  second += time;
  while(second>59) {
    second -= 60;
    minute++;
  }
  while(minute>59) {
    minute -= 60;
    hour++;
  }
  while(hour>23) {
    hour -= 24;
  }
  printf("%d %d %d\n", hour, minute, second);
  return 0;
}