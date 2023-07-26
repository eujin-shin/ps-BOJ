#include <stdio.h>

int main() {
  int N, Y, M;
  Y = 0;
  M = 0;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    int time;
    scanf("%d", &time);
    int time_Y = time;
    Y+=10;
    while(time_Y>=30) {
      time_Y-=30;
      Y+=10;
    }
    int time_M = time;
    M+=15;
    while(time_M>=60) {
      time_M-=60;
      M+=15;
    }
  }
  if(Y>M) {
    printf("M %d\n", M);
  } else if(M>Y) {
    printf("Y %d\n", Y);
  } else {
    printf("Y M %d\n", Y);
  }
  return 0;
}