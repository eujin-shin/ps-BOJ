#include <stdio.h>

int main() {
  int hour, minute, N;
  scanf("%d %d\n%d", &hour, &minute, &N);
  minute += N;
  while(minute>=60) {
    minute -= 60;
    hour += 1;
  }
  while(hour>=24) {
    hour -= 24;
  }
  printf("%d %d\n", hour, minute);
  return 0;
}