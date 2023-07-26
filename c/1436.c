#include <stdio.h>
#include <string.h>

int main() {
  int n; 
  scanf("%d", &n);
  int num;
  num = 5;
  while(n) {
    num++;
    char num_arr[11] = {'0', };
    sprintf(num_arr, "%d", num);
    char* result = strstr(num_arr, "666");
    if(result!=NULL) {
      n--;
    }
  }
  printf("%d\n", num);
  return 0;
}