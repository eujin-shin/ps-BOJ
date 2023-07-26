#include <iostream>
using namespace std;

int map[40][40]={0, }, s[4][10][10], k, n, m;

void Stitch(int x, int y, int r, int c, int i) {
  for(int h=0; h<r; h++) {
    for(int j=0; j<c; j++) {
      if(s[i][h][j]==1) {
        map[h+y][j+x]=1;
      }
    }
  }
  return;
}

int Check(int x, int y, int r, int c, int i) {
  for(int h=0; h<r; h++) {
    for(int j=0; j<c; j++) {
      if(map[h+y][j+x]==1 && s[i][h][j]==1) {
        return -1;
      }
    }
  }
  Stitch(x, y, r, c, i);
  return 1;
}

int Solve(int r, int c) {
  int tmp;
  for(int i=0; i<4; i++) {
    if(i>0) {
      tmp=r; r=c; c=tmp;
    }
    for(int y=0; y<=n-r; y++) {
      for(int x=0; x<=m-c; x++) {
        if(Check(x, y, r, c, i)>0) return 1;
      }
    }
  }
  return 0;
}

void Print() {
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) {
      cout<<map[i][j];
    }
    cout<<'\n';
  }
  return;
}

int main() {
  int r, c, sum=0, cnt, tmp;
  cin>>n>>m>>k;
  while(k--) {
    cin>>r>>c;
    cnt=0;
    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        cin>>tmp;
        if(tmp==1) cnt++;
        s[0][i][j]=tmp;
        s[1][j][r-1-i]=tmp;
        s[2][r-1-i][c-1-j]=tmp;
        s[3][c-1-j][i]=tmp;
      }
    }
    if(Solve(r, c)>0) sum+=cnt;
  }
  cout<<sum<<'\n';
  return 0;
}