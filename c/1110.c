#include <stdio.h>

int Cycle(int N) {
  int c = 0;
  int i = N;
  do {
    int n = i%10;
    if(i<10) {
      i = (10*n)+i;
    } else {
      int a = i/10+i%10;
      i = (10*n)+(a%10);
    }
    c++;
  } while (i!=N);
  return c;
}

int main() {
  int N;
  scanf("%d", &N);
  printf("%d\n", Cycle(N));
  return 0;  
}