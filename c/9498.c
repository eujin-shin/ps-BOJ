#include <stdio.h>

int Grade(int score) {
  if(score>=90) {
    printf("A\n");
  } else if(score>=80) {
    printf("B\n");
  } else if(score>=70) {
    printf("C\n");
  } else if(score>=60) {
    printf("D\n");
  } else {
    printf("F\n");
  }
  return 0;
}

int main() {
  int score;
  scanf("%d", &score);
  Grade(score);
  return 0;
}