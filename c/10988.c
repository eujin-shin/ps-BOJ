#include <stdio.h>
#include <string.h>

int main() {
  char word[101];
  int check = 1;
  scanf("%s", word);
  int len = strlen(word);
  for(int i=0; i<=len/2; i++) {
    if(word[i]!=word[len-i-1]) {
      check = 0;
      break;
    }
  }
  printf("%d\n", check);
  return 0;
}