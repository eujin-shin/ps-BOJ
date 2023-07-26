#include <stdio.h>

int main() {
  int E, S, M, num;
  scanf("%d %d %d", &E, &S, &M);
  num = E;
  E %= 15;
  S %= 28;
  M %= 19;
  while(1) {
    if(num%28==S && num%19==M) {
      break;
    }
    num += 15;
  }
  printf("%d\n", num);
  return 0;
}