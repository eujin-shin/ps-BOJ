#include <stdio.h>

int main() {
  int T, ans;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    ans = 0;
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=N; i<=M; i++) {
      int num = i;
      if(num==0) {
        ans+=1;
        continue;
      }
      while(num>0) {
        if(num%10==0) {
          ans+=1;
        }
        num/=10;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}