#include <iostream>
#include <queue>
#include <string>
using namespace std;

string map[10];
int n, m;

int main() {
  int rx, ry, bx, by;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>map[i];
    for(int j=0; j<m; j++) {
      if(map[i][j]=='R') {
        ry=i; rx=j;
      } else if(map[i][j]=='B') {
        by=i; bx=j;
      }
    }
  }
  
}