#include <stdio.h>
#include <string.h>

int main() {
  int laser[100001] = {0, };
  int start_arr[50001] = {0, };
  char set[100001];
  int N, start, count;
  scanf("%s", set);
  N = strlen(set);
  start = 1;
  count = 0;
  for(int i=1; i<=N; i++) {
    if(set[i-1]=='(') {
      if(set[i]==')') {
        laser[i+1] = laser[i-1] + 1;
        i++;
      } else {
        start_arr[start] = i;
        start++;
        laser[i] = laser[i-1];
      }
    } else {
      start--;
      laser[i] = laser[i-1];
      count += 1 + laser[i] - laser[start_arr[start]];
    }
  }
  printf("%d\n", count);
  return 0;
}