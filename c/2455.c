#include <stdio.h>

int main() {
  int ride, takeoff, train, max;
  max = 0;
  train = 0;
  for(int i=0; i<4; i++) {
    scanf("%d %d", &takeoff, &ride);
    train += ride;
    train -= takeoff;
    if(train>max) {
      max = train;
    }
  }
  printf("%d\n", max);
  return 0;
}