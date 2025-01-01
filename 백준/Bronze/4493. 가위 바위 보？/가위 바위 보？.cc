#include <iostream>
using namespace std;

bool firstPlayerWins(char a, char b) {
  return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, x, y;
  char a, b;
  cin>>t;
  while(t--) {
    cin>>n;
    x = 0;
    y = 0;
    for(int i = 0; i < n; i++) {
      cin>>a>>b;
      if(a == b) {
        x++;
        y++;
      } else if(firstPlayerWins(a, b)) {
        x++;
      } else {
        y++;
      }
    }
    if(x > y) {
      cout<<"Player 1\n";
    } else if(y > x) {
      cout<<"Player 2\n";
    } else {
      cout<<"TIE\n";
    }
  }
  return 0;
}