#include <stdio.h>

int main() {
  int start, end, T, goal, count, ans;
  long long dis;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d %d", &start, &end);
    goal = end - start;
    if(goal<4) {
      printf("%d\n", goal);
      continue;
    }
    dis = 1;
    count = 1;
    while(dis+2*count+1<=goal) {
      dis += 2*count+1;
      count++;
    }
    if(goal-dis<count) {
      ans = count*2;
      if(goal-dis==0) {
        ans--;
      }
    } else {
      ans = count*2+(goal-dis)/count;
      if((goal-dis)%count==0) {
        ans--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}