#include <iostream>
using namespace std;

int map[2000][2000]={0, };
int arr[2000]={0, };

int GetDp(int x, int y) {
  if(map[x][y]!=0) return map[x][y];
  if(arr[y]!=arr[x]) map[x][y]=-1;
  else if(x==y || y==x+1) map[x][y]=1;
  else map[x][y]=GetDp(x+1, y-1);
  return map[x][y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, e, ans;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>s>>e;
    ans=GetDp(s-1, e-1);
    if(ans<0) ans++;
    cout<<ans<<'\n';
  }
  return 0;
}