#include <stdio.h>
#include <string.h>

int main() {
  int alp[26] = {0, };
  char name[51];
  char ans[51];
  int n, flag, index, check;
  scanf("%s", name);
  n = strlen(name);
  for(int i=0; i<n; i++) {
    alp[name[i]-'A'] = alp[name[i]-'A']+1;
  }
  flag = 0;
  index = 0;
  check = 0;
  for(int i=0; i<26; i++) {
    while(alp[i]>1) {
      alp[i] = alp[i] - 2;
      ans[index] = i+'A';
      ans[n-1-index] = i+'A';
      index++;
    }
    if(alp[i]) {
      if(check) {
        printf("I'm Sorry Hansoo\n");
        return 0;
      } else {
        flag = i;
        check = 1;
      }
    }
  }
  if(check) {
    ans[n/2] = flag+'A';
  }
  for(int i=0; i<n; i++) {
    printf("%c", ans[i]);
  }
  printf("\n");
  return 0;
}