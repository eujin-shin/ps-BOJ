#include <stdio.h>

int main() {
  int S1, S2, S3;
  scanf("%d %d %d", &S1, &S2, &S3);
  int max = S1 + S2 + S3;
  int CountArr[max+1];
  for(int i=0; i<=max; i++) {
    CountArr[i]=0;
  }
  for(int i=1; i<=S1; i++) {
    for(int j=1; j<=S2; j++) {
      for(int k=1; k<=S3; k++) {
        CountArr[i+j+k]+=1;
      }
    }
  }
  int answerCount = 0;
  int answer;
  for(int i=max; i>0; i--) {
    if(answerCount<=CountArr[i]) {
      answerCount = CountArr[i];
      answer = i;
    }
  }
  printf("%d\n", answer);
  return 0;
 }