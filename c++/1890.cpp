#include <iostream>
using namespace std;

int map[100][100]={0, };
long long mem[100][100]={0, };


long long DFS(int x, int y, int n) {
  if(x>=n || y>=n) return 0;
  if(mem[x][y]!=0) {
    if(mem[x][y]<0) return 0;
    return mem[x][y];
  }
  int move=map[x][y];
  if(move==0) return 0;
  mem[x][y]=DFS(x+move, y, n)+DFS(x, y+move, n);
  if(mem[x][y]==0) {
    mem[x][y]=-1; return 0;
  } 
  return mem[x][y];
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[j][i];
    }
  }
  mem[n-1][n-1]=1;
  cout<<DFS(0, 0, n)<<'\n';
  return 0;
}