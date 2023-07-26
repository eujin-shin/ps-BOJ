#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  int roomArr[T];
  for(int i=0; i<T; i++) {
    int H, W, N, a, b;
    a=0; b=0;
    scanf("%d %d %d", &H, &W, &N);
    b=1+(N-1)/H;
    if(N%H!=0) {
      a=N%H;
    } else {
      a=H;
    }
    roomArr[i]=a*100+b;
  }
  for(int i=0; i<T; i++) {
    printf("%d\n", roomArr[i]);
  }
  return 0;
}