#include <stdio.h>

int time_set[3][4];
int left_time[3];

int Get_Bigger() {
  int bigger;
  for(int i=0; i<3; i++) {
    if(time_set[0][i]>time_set[1][i]) {
      bigger = 0;
    } else if(time_set[1][i]>time_set[0][i]) {
      bigger = 1;
    }
  }
  return bigger;
}

int Get_Lefttime(int bigger) {
  int smaller = !bigger;
  for(int i=0; i<3; i++) {
    left_time[i] = time_set[bigger][i] - time_set[smaller][i];
  }
  for(int i=2; i>0; i--) {
    if(left_time[i]<0) {
      left_time[i] += 60;
      left_time[i-1] --;
    }
  }
  return 0;
}

int main() {
  int hour, minute, second;
  scanf("%d:%d:%d", &time_set[0][0], &time_set[0][1], &time_set[0][2]);
  scanf("%d:%d:%d", &time_set[1][0], &time_set[1][1], &time_set[1][2]);
  int bigger = Get_Bigger();
  Get_Lefttime(bigger);
  printf("%2d:%2d:%2d\n", left_time[0], left_time[1], left_time[2]);
  return 0;
}