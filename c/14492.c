#include <stdio.h>

int A[301][301];
int B[301][301];

int GetOne(int N) {
  int exit;
  int count = 0;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      exit = 0;
      for(int k=1; k<=N; k++) {
        exit = A[i][k] && B[k][j];
        if(exit==1) {
          count++;
          break;
        }
      }
    }
  }
  return count;
}

int main() {
  int N;
  scanf("%d", &N);
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &B[i][j]);
    }
  }
  int ans = GetOne(N);
  printf("%d\n", ans);
  return 0;
}