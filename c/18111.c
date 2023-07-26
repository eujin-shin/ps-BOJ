#include <stdio.h>

int GetMore(int map[], int cur, int n) {
  int more = 0;
  for(int i=n; i>cur; i--) {
    more += (i-cur)*map[i];
  }
  return more;
}

int GetLess(int map[], int cur, int n) {
  int less = 0;
  for(int i=n; i<cur; i++) {
    less += (cur-i)*map[i];
  }
  return less;
}

int main() {
  int map[300] = {0, };
  int n, m, b, temp, min, max, time, height, more, less;
  scanf("%d %d %d", &n, &m, &b);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%d", &temp);
      if(i+j==0) {
        min = temp;
        max = temp;
      } else if(min>temp) {
        min = temp;
      } else if(max<temp) {
        max = temp;
      }
      map[temp] = map[temp]+1;
    }
  }
  time = -1;
  for(int i=max; i>=min; i--) {
    more = GetMore(map, i, max);
    less = GetLess(map, i, min);
    if (b+more<less) continue;
    temp = more*2+less;
    if(time == -1 || temp<time) {
      time = temp;
      height = i;
    }
  }
  printf("%d %d\n", time, height);
  return 0;
}