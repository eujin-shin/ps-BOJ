#include <iostream>
#define M 7000
using namespace std;

char map[M][M]={0, };

void Print(int n, int x, int y) {
  if(n>3) {
    n/=3;
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if(i==1 && j==1) continue;
        Print(n, x+i*n, y+j*n);
      }
    }
  } else {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if(i==1 && j==1) continue;
        map[x+i][y+j]=1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  Print(n, 0, 0);
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      if(map[x][y]==1) cout<<'*';
      else cout<<' ';
    }
    cout<<'\n';
  }
  return 0;
}