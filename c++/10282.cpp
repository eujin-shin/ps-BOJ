#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v[10001];
int arr[10001]={0, };
priority_queue <pnt, vector<pnt>, greater<pnt> > q;

int main() {
  ios_base::sync_with_stdio(false);
  int t, n, d, c, a, b, s, tmp, ans, max;
  cin>>t;
  while(t--) {
    cin>>n>>d>>c;
    memset(arr, -1, sizeof(arr));
    for(int i=0; i<d; i++) {
      cin>>a>>b>>s;
      v[b].push_back(make_pair(s, a));
    }
    ans=0; max=0;
    q.push(make_pair(0, c)); arr[c]=0;
    while(!q.empty()) {
      a=q.top().second;
      s=q.top().first;
      q.pop();
      if(arr[a]<s) continue;
      for(int i=0; i<v[a].size(); i++) {
        b=v[a][i].second;
        tmp=s+v[a][i].first;
        if(arr[b]>=0 && arr[b]<=tmp) continue;
        arr[b]=tmp; q.push(make_pair(tmp, b));
      }
    }
    for(int i=1; i<=n; i++) {
      v[i].clear();
      if(arr[i]<0) continue;
      ans++;
      max=((max<arr[i]) ? (arr[i]) : (max));
    }
    cout<<ans<<' '<<max<<'\n';
  }
  return 0;
}