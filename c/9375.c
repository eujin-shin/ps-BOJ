#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int t, n, index, flag, ans;
  char cloth[30], kind[30];
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    scanf("%d", &n);
    int num[31] = {0, };
    index = 1;
    char **clothes = (char **)malloc(sizeof(char *)*(n+1));
    for(int j=1; j<=n; j++) {
      scanf("%s %s", cloth, kind);
      flag = 0;
      for(int k=1; k<index; k++) {
        if(!strcmp(*(clothes+k), kind)) {
          flag = k; 
          break;
        }
      }
      if(flag) {
        num[flag] = num[flag]+1;
      } else {
        *(clothes+index) = (char *)malloc(sizeof(char)*(strlen(kind)+1));
        strcpy(*(clothes+index), kind);
        num[index] = 2;
        index++;
      }
    }
    ans = 1;
    for(int i=1; i<index; i++) {
      ans *= num[i];
    }
    printf("%d\n", ans-1);
  }
  return 0;
}