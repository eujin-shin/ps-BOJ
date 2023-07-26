#include <stdio.h>
#include <string.h>

int main() {
  int count, len_doc, len_word, flag;
  char doc[2600], word[60];
  scanf("%[^\n]s", doc);
  getchar();
  scanf("%[^\n]s", word);
  len_doc = strlen(doc);
  len_word = strlen(word);
  count = 0;
  for(int i=0; i<=len_doc-len_word; i++) {
    flag = 1;
    for(int j=0; j<len_word; j++) {
      if(doc[i+j]!=word[j]) {
        flag = 0;
        break;
      }
    }
    if(flag) {
      count++;
      i+=len_word-1;
    }
  }
  printf("%d\n", count);
  return 0;
}