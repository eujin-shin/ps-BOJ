#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

queue <int> q;
int arr[20001];
vector <int> g[20001];

void SetGraph(int v, int e) {
  int x, y;
  q = queue <int>();
  for(int i=1; i<=v; i++) g[i]=vector<int>();
  for(int i=0; i<e; i++) {
    cin>>x>>y;
    g[x].push_back(y); g[y].push_back(x);
  }
  return;
}

bool BiGraph(int root) {
  bool flag=true;
  int cur, adj, count=1, next=0;
  q.push(root); arr[root]=1;
  while(!q.empty()) {
    cur=q.front(); q.pop();
    for(int i=0; i<g[cur].size(); i++) {
      adj=g[cur][i];
      if(arr[adj]==arr[cur]) {
        return false;
      } else if(arr[adj]==0) {
        arr[adj]=arr[cur]*(-1);
        q.push(adj); next++;
      }
    }
    count--;
    if(count==0) {
      count=next; next=0;
    }
  }
  return true;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k, v, e, cur, count, next, tmp;
  bool flag;
  cin>>k;
  while(k--) {
    cin>>v>>e;
    memset(arr, 0, sizeof(arr));
    SetGraph(v, e);
    for(int i=1; i<=v; i++) {
      if(arr[i]!=0) continue;
      flag=BiGraph(i);
      if(!flag) break;
    }
    cout<<(flag ? "YES\n" : "NO\n");
  }
  return 0;
}

// queue 초기화 안 해서 문제됨