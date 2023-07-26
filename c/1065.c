#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int ans = 0;
  for(int i=1; i<=N; i++) {
    if(i<100) {
      ans++;
    }
    else if(i==1000) {
      continue;
    }
    else {
      int Arr[3];
      int a = i;
      for(int x=0; x<3; x++) {
        Arr[x]=a%10;
        a/=10;
      }
      if((Arr[2]-Arr[1])==(Arr[1]-Arr[0])) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}