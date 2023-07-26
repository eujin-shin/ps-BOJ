#include <stdio.h>

int main() {
  int ans = 0;
  int N, T, k, index;
  scanf("%d %d", &N, &T);
  int book_set[N];
  index = 0;
  for(int i=0; i<T; i++) {
    scanf("%d", &k);
    scanf("%d", &book_set[index]);
    index++;
    for(int j=1; j<k; j++) {
      scanf("%d", &book_set[index]);
      if(book_set[index]>book_set[index-1]) {
        ans = 1;
      }
      index++;
    }
  }
  if(ans==1) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  return 0;
}