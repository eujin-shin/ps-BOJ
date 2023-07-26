#include <iostream>
using namespace std;

int map[21][21]={0, };
int arr[21]={0, };
int ans=-1;

void GetSum(int n) {
  int a=0, b=0, dif;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(i==j) continue;
      if(arr[i]==1 && arr[j]==1) a+=map[i][j];
      if(arr[i]==0 && arr[j]==0) b+=map[i][j];
    }
  }
  dif=a-b;
  if(dif<0) dif=-dif;
  if(ans<0 || dif<ans) ans=dif;
  return;
}

void Btrack(int n, int x, int r) {
  if(r==n/2) {
    GetSum(n); return;
  }
  for(int i=x; i<=n-(n/2-r)+1; i++) {
    arr[i]=1;
    Btrack(n, i+1, r+1);
    arr[i]=0;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>map[i][j];
    }
  }
  Btrack(n, 1, 0);
  cout<<ans<<'\n';
  return 0;
}