#include <iostream>
using namespace std;

int map[2][51][101]={0, }, visit[2][51][101], arr[101]={0, };

int Max(int a, int b, int base) {
  int tmp=-1;
  if(a>=0) tmp=a+base;
  if(b>=0 && b>a) tmp=b+base;
  return tmp;
}

int main() {
  int n, m, ans=0;
  cin>>n>>m;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=0; i<=n; i++) {
    visit[0][0][i]=1;
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      if(visit[0][j-1][i-1]) {
        visit[1][j][i]=1;
        map[1][j][i]=arr[i]+map[0][j-1][i-1];
      }
      if(visit[1][j][i-1]) {
        visit[1][j][i]=1;
        if(map[1][j][i]<arr[i]+map[1][j][i-1]) {
          map[1][j][i]=arr[i]+map[1][j][i-1];
        }
        visit[0][j][i]=1;
        map[0][j][i]=map[1][j][i-1];
      }
      if(visit[0][j][i-1]) {
        visit[0][j][i]=1;
        if(map[0][j][i]<map[0][j][i-1]) {
          map[0][j][i]=map[0][j][i-1];
        }
      }
    }
  }
  cout<<((map[0][m][n]>map[1][m][n]) ? (map[0][m][n]) : (map[1][m][n]))<<'\n';
  return 0;
}