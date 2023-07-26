#include <stdio.h>

int main() {
  int C;
  scanf("%d", &C);
  double resultArr[C];
  for(int i=0; i<C; i++) {
    int n;
    scanf("%d", &n);
    int studentArr[n]; 
    int sum = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &studentArr[i]);
      sum += studentArr[i];
    }
    double n2 = n;
    double sum2 = sum;
    double avr = sum2/n2;
    int up = 0;
    for(int i=0; i<n; i++) {
      double a = studentArr[i];
      if(a>avr) {
        up++;
      }
    }
    double up2 = up;
    double result = up2 / n2 *100;
    resultArr[i] = result;
  }
  for(int i=0; i<C; i++) {
    printf("%.3f%%\n", resultArr[i]);
  }
  return 0;
}
