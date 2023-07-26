#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector <int> g[20001];
queue <int> q;
int arr[20001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k, v, e, x, y, s, cur, count, next, tmp;
  bool flag;
  cin>>k;
  while(k--) {
    cin>>v>>e;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<e; i++) {
      cin>>x>>y;
      g[x].push_back(y); g[y].push_back(x);
    }
    q.push(1);
    flag=true;
    s=-1; arr[1]=1; count=1; next=0;
    while(!q.empty()) {
      cur=q.front(); q.pop();
      for(int i=0; i<g[cur].size(); i++) {
        tmp=g[cur][i];
        if(s*-1==arr[tmp]) {
          flag=false; break;
        }
        if(arr[tmp]==0) {
          q.push(tmp); next++; arr[tmp]=s;
        }
      }
      if(!flag) break;
      count--;
      if(count==0) {
        count=next; next=0; s=-s;
      }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}