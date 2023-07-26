#include <stdio.h>
#include <string.h>

int main() {
  char str[100010], str_rev[100010];
  int n, i, x=0, y=0;
  scanf("%[^\n]s", str);
  n = strlen(str);
  for(i=0; i<n; i++) {
    if(str[i]=='<') {
      str_rev[i]='<';
      do {
        i++;
        str_rev[i]=str[i];
      } while(str[i]!='>');
    } else if(str[i]==' ') {
      str_rev[i] = ' ';
    } else {
      x = i;
      do {
        i++;
      } while(str[i]!=' ' && str[i]!='<' && i!=n);
      i--;
      y = i;
      for(int j=0; j<=y-x; j++) {
        str_rev[x+j] = str[y-j];
      }
      x = 0;
    }
  }
  printf("%s\n", str_rev);
  return 0;
}