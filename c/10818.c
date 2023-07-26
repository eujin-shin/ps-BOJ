#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int Arr[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &Arr[i]);
  }
  int max = Arr[0], min = Arr[0];
  for(int i=1; i<N; i++) {
    if(max<Arr[i]) {
      max = Arr[i];
    }
  }
  for(int i=1; i<N; i++) {
    if(min>Arr[i]) {
      min = Arr[i];
    }
  }
  printf("%d %d\n", min, max);
  return 0;
}