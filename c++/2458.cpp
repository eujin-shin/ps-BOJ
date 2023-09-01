#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, cnt, arr[501]={0, };
vector <int> l[501], s[501];

void FindLong(int x) {
  int next;
  for(int i=0; i<l[x].size(); i++) {
    next=l[x][i];
    if(arr[next]==0) {
      arr[next]=1; cnt++; FindLong(next);
    }
  }
  return;
}

void FindShort(int x) {
  int next;
  for(int i=0; i<s[x].size(); i++) {
    next=s[x][i];
    if(arr[next]==0) {
      arr[next]=-1; cnt++; FindShort(next);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int m, a, b, ans=0;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    l[a].push_back(b);
    s[b].push_back(a);
  }
  for(int i=1; i<=n; i++) {
    memset(arr, 0, sizeof(arr));
    cnt=1;
    FindLong(i);
    FindShort(i);
    if(cnt==n) ans++;
  }
  cout<<ans<<'\n';
  return 0;
}