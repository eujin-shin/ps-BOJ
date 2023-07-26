#include <stdio.h>
#include <string.h>

int main() {
  int x, n, ans;
  while(1) {
    char match[101];
    char in_str[102];
    fgets(in_str, 102, stdin);
    n = strlen(in_str);
    x = 0;
    ans = 1;
    for(int i=0; i<n; i++) {
      if(in_str[i]=='(' || in_str[i]=='[') {
        match[x] = in_str[i];
        x++;
      } else if(in_str[i]==')') {
        if(x-1>=0 && match[x-1]=='(') {
          x--;
        } else {
          ans = 0;
          break;
        }
      } else if(in_str[i]==']') {
        if(x-1>=0 && match[x-1]=='[') {
          x--;
        } else {
          ans = 0;
          break;
        }
      }
    }
    if(x>0) {
      ans = 0;
    }
    if(n==2 && in_str[0]== '.') {
      break;
    }
    if(ans) {
      printf("yes\n");
    } else {
      printf("no\n");
    }    
    
  }
  return 0;
}