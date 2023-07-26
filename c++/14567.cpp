#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int sub[1001]={0, };
  int ind[1001]={0, };
  vector <int> out[1001];
  int n, m, a, b, count=1, cur=0, next=0, s;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    out[a].push_back(b);
    ind[b]++;
  }
  queue <int> sem;
  for(int i=1; i<=n; i++) {
    if(ind[i]==0) {
      sem.push(i);
      cur++;
    }
  }
  while(!sem.empty()) {
    s=sem.front(); sem.pop();
    sub[s]=count;
    for(int i=0; i<out[s].size(); i++) {
      ind[out[s][i]]--;
      if(sub[out[s][i]]==0 && ind[out[s][i]]==0) {
        sem.push(out[s][i]); next++;
      }
    }
    cur--;
    if(cur==0) {
      cur=next; next=0; count++;
    }
  }
  for(int i=1; i<=n; i++) {
    cout<<sub[i];
    if(i==n) cout<<'\n';
    else cout<<' ';
  }
}