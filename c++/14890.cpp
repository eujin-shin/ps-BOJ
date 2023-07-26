#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int map[101][101]={0, };
  int n, l;
  cin>>n>>l;
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      cin>>map[x][y];
    }
  }
  bool flag;
  int count=0, level, cont;
  for(int x=0; x<n; x++) {
    flag=true;
    cont=1; level=map[x][0];
    for(int y=1; y<n; y++) {
      if(map[x][y]==level) {
        cont++;
      } else if(map[x][y]==level+1 && cont>=l) {
        level++; cont=1;
      } else if(map[x][y]==level-1) {
        for(int i=1; i<l; i++) {
          if(y+i>=n || map[x][y+i]!=map[x][y]) {
            flag=false; break;
          }
        }
        if(!flag) break;
        cont=0; level--; y+=l-1;
      } else {
        flag=false; break;
      }
    }
    if(flag) {
      count++;
    }
  }
  for(int y=0; y<n; y++) {
    flag=true;
    cont=1; level=map[0][y];
    for(int x=1; x<n; x++) {
      if(map[x][y]==level) {
        cont++;
      } else if(map[x][y]==level+1 && cont>=l) {
        level++; cont=1;
      } else if(map[x][y]==level-1) {
        for(int i=1; i<l; i++) {
          if(x+i>=n || map[x+i][y]!=map[x][y]) {
            flag=false; break;
          }
        }
        if(!flag) break;
        cont=0; level--; x+=l-1;
      } else {
        flag=false; break;
      }
    }
    if(flag) {
      count++;
    }
  }
  cout<<count<<'\n';
  return 0;
}