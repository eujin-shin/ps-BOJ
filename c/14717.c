#include <stdio.h>

int main() {
  int a, b, S;
  S = 9*17;
  scanf("%d %d", &a, &b);
  if(a==b) {
    int lose = 10 - a;
    int win = S - lose;
    double P = (double)win / (double)S;
    printf("%.3f\n", P);
  } else {
    int point = (a+b)%10;
    int card_set[20];
    int index = 0;
    for(int i=0; i<2; i++) {
      for(int j=1; j<=10; j++) {
        card_set[index] = j;
        index += 1;
      }
    }
    card_set[a-1] = 0;
    card_set[b-1] = 0;
    int win = 0;
    for(int i=0; i<19; i++) {
      for(int j=i+1; j<20; j++) {
        if(card_set[i]!=0 && card_set[j]!=0 && card_set[i]!=card_set[j]) {
          int player_point = (card_set[i]+card_set[j])%10;
          if(player_point<point) {
            win += 1;
          }
        }
      }
    }
    double P = (double)win / (double)S;
    printf("%.3f\n", P);
  }
  return 0;
}