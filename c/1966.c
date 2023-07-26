#include <stdio.h>
#include <stdlib.h>

int main() {
  int* queue;
  int* ans_arr;
  int t, size, m, max, index, count, ans, import_m;
  scanf("%d", &t);
  ans_arr = (int *)malloc(sizeof(int)*t);
  for(int i=0; i<t; i++) {
    scanf("%d %d", &size, &m);
    queue = (int *)malloc(sizeof(int)*size);
    int import[10] = {0, };
    max = 0;
    for(int j=0; j<size; j++) {
      scanf("%d", queue+j);
      import[*(queue+j)] = import[*(queue+j)] + 1;
      if(*(queue+j)>max) {
        max = *(queue+j);
      }
    }
    index = 0;
    ans = 0;
    import_m = queue[m];
    for(int j=max; j>=import_m; j--) {
      count = import[j];
      while(count) {
        if(queue[index]==j) {
          queue[index]=0;
          ans++;
          count--;
          if(index==m) {
            break;
          }
        }
        index++;
        if(index>=size) {
          index-=size;
        }
      }
    }
    *(ans_arr+i) = ans;
  }
  for(int i=0; i<t; i++) {
    printf("%d\n", *(ans_arr+i));
  }
  return 0;
}