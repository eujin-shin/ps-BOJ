#include <stdio.h>

void quick_sort(int num[], int start, int end) {
  int i, j, pivot, temp;
  if(start<end) {
    pivot = num[start];
    i = start+1;
    j = end;
    do {
      while(num[i]<pivot) {
        i++;
      };
      while(num[j]>pivot) {
        j--;
      };
      if (i<j) {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    } while (i<j);
    num[start] = num[j];
    num[j] = pivot;
    quick_sort(num, start, j-1);
    quick_sort(num, j+1, end);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int num[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &num[i]);
  }
  quick_sort(num, 0, n-1);
  for(int i=0; i<n; i++) {
    printf("%d\n", num[i]);
  }
  return 0;
}