#include <stdio.h>
#include <math.h>

int main() {
  int prime_chart[246913] = {0, };
  for(int i=2; i<sqrt(246912); i++) {
    if(prime_chart[i]==1) {
      continue;
    }
    for(int j=2; i*j<=246912; j++) {
      prime_chart[i*j] = 1;
    }
  }
  int count = 0;
  for(int i=2; i<=246912; i++) {
    if(prime_chart[i]==0) {
      count++;
    }
    prime_chart[i] = count;
  }
  int n;
  while(1) {
    scanf("%d", &n);
    if(n==0) {
      break;
    }
    printf("%d\n", prime_chart[2*n]-prime_chart[n]);
  }
  return 0;
}