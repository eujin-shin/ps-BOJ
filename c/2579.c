#include <stdio.h>

int stairs[301] = {0, };
int scores[2][302] = {0, };

int GetScore(int n) {
  int score;
  if(n>2 && scores[0][n]==0) {
    GetScore(n-1);
    scores[1][n] = scores[0][n-1] + stairs[n];
    scores[0][n] = GetScore(n-2) + stairs[n];
  }
  if(scores[1][n]>scores[0][n]) {
    score = scores[1][n];
  } else {
    score = scores[0][n];
  }
  return score;
}

int main() {
  int n, score;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &score);
    stairs[i] = score;
  }
  scores[1][1] = stairs[1];
  scores[0][2] = stairs[2];
  scores[1][2] = stairs[1] + stairs[2];
  printf("%d\n", GetScore(n));
  return 0;
}