#include <stdio.h>

int C_Data[31][31] = {0, };

int C(int N, int M) {
  if(N==0 || N==M) {
    return 1;
  } else if (C_Data[N][M]==0) {
    C_Data[N][M] = C(N, M-1) + C(N-1, M-1);
  }
  return C_Data[N][M];
}

int main() {
  int T, N, M;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d %d", &N, &M);
    printf("%d\n", C(N, M));
  }
  return 0;
}