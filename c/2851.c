#include <stdio.h>

int main() {
  int score_set[10];
  for(int i=0; i<10; i++) {
    scanf("%d", &score_set[i]);
  }
  int score_sum = 0;
  int new_score = 0;
  for(int i=0; i<10; i++) {
    int score = score_set[i];
    new_score += score;
    if(new_score>99) {
      if((new_score-100)<=(100-score_sum)) {
        score_sum = new_score;
        break;
      } else {
        break;
      }
    }
    score_sum = new_score;
  }
  printf("%d\n", score_sum);
  return 0;
}