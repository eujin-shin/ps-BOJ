#include <stdio.h>

int main() {
  int N, M, ans, book, box_index, box_left;
  ans = 0;
  scanf("%d %d", &N, &M);
  int boxArr[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &boxArr[i]);
  }
  box_index = 0;
  box_left = boxArr[0];
  for(int i=0; i<M; i++) {
    scanf("%d", &book);
    while(box_left<book) {
      ans += box_left;
      box_index += 1;
      box_left = boxArr[box_index];
    }
    box_left -= book;
  }
  ans += box_left;
  for(int i=box_index+1; i<N; i++) {
    ans += boxArr[i];
  }
  printf("%d\n", ans);
  return 0;
}