#include <stdio.h>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  int cardArr[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &cardArr[i]);
  }
  int ans = 0;
  for(int i=0; i<N-2; i++) {
    int a = cardArr[i];
    for(int k=i+1; k<N-1; k++) {
      int b = cardArr[k];
      for(int j=k+2; j<N; j++) {
        int c = cardArr[j];
        printf("%d %d %d\n", a, b, c);
        int sum = a+b+c;
        if(sum<=M && sum>ans) {
          ans = sum;
        } else {
          continue;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}