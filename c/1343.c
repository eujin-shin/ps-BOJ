#include <stdio.h>
#include <string.h>

int main() {
  char input_s[51];
  char output_s[51];
  int n, check = 0, count = 0;
  scanf("%s", input_s);
  n = strlen(input_s);
  for(int i=0; i<=n; i++) {
    if(input_s[i]=='.' || i==n) {
      if(count==2) {
        count = 0;
        output_s[i-2] = 'B';
        output_s[i-1] = 'B'; 
        output_s[i] = '.';
      } else if (count==0){
        output_s[i] = '.';
      } else {
        check = -1;
        break;
      }
    } else {
      count++;
      if(count==4) {
        output_s[i-3] = 'A';
        output_s[i-2] = 'A';
        output_s[i-1] = 'A';
        output_s[i] = 'A';
        count = 0;
      }
    }
  }
  if(check==-1) {
    printf("%d\n", check);
  } else {
    for(int i=0; i<n; i++) {
      printf("%c", output_s[i]);
    }
    printf("\n");
  }
  return 0;
}