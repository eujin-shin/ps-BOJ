#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int map[502][502] = {0, };
  int rain = 0, h, w, temp;
  cin>>h>>w;
  for(int i=0; i<w; i++) {
    cin>>temp;
    for(int j=0; j<temp; j++) {
      map[i][j] = 1;
    }
  }
  int a, b;
  for(int y=0; y<h; y++) {
    a = -1;
    for(int x=0; x<w; x++) {
      if(map[x][y]==1) {
        if(x==a+1) a++;
        else if(a==-1) a=x;
        else {
          b = x;
          for(int i=a+1; i<b; i++) {
            map[i][y] = 1;
            rain++;
          }
          a = b;
        }
      }
    }
  }
  cout<<rain<<'\n';
  return 0;
}