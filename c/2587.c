#include <stdio.h>

int main() {
  int numArr[5], sum, temp;
  sum = 0;
  for(int i=0; i<5; i++) {
    scanf("%d", &numArr[i]);
    sum += numArr[i];
  }
  int average = sum/5;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4-i; j++) {
      if(numArr[j]>numArr[j+1]) {
        temp = numArr[j];
        numArr[j] = numArr[j+1];
        numArr[j+1] = temp;
      }
    }
  }
  printf("%d\n", average);
  for(int i=0; i<5; i++) {
    printf("%d\n", numArr[i]);
  }
  return 0;
}