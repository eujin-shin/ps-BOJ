#include <iostream>
#define MIN -100000000
using namespace std;

int map[1001][1001]={0, }, l[1001][1001]={0, }, r[1001][1001]={0, }, n, m;

void right(int i) {
  int max=MIN;
  for(int j=1; j<=m; j++) {
    if(j>1) max=r[i][j-1];
    if(max<r[i-1][j]) max=r[i-1][j];
    if(max<l[i-1][j]) max=l[i-1][j];
    r[i][j]=max+map[i][j];
  }
  return;
}

void left(int i) {
  int max=MIN;
  for(int j=m; j>0; j--) {
    if(j<m) max=l[i][j+1];
    if(max<l[i-1][j]) max=l[i-1][j];
    if(max<r[i-1][j]) max=r[i-1][j];
    l[i][j]=max+map[i][j];
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) cin>>map[i][j];
  }
  for(int i=1; i<=m; i++) r[1][i]=r[1][i-1]+map[1][i];
  l[1][1]=map[1][1];
  for(int i=2; i<=m; i++) l[1][i]=MIN;
  for(int i=2; i<n; i++) {
    right(i); left(i);
  }
  right(n);
  cout<<r[n][m]<<'\n';
  return 0;
}