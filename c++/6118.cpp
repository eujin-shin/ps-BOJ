#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[20001];
queue <int> q;
int arr[20001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, a, b;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    v[a].push_back(b); v[b].push_back(a);
  }
  int level=0, cur, tmp, t=0, cnt=1, next=0, min=-1;
  q.push(1); arr[1]=1;
  while(!q.empty()) {
    if(t==cnt) {
      t=0; level++; cnt=next; next=0; min=-1;
    }
    cur=q.front(); q.pop();
    if(min<0 || cur<min) min=cur;
    for(int i=0; i<v[cur].size(); i++) {
      tmp = v[cur][i];
      if(arr[tmp]!=0) continue;
      arr[tmp]=1; q.push(tmp);
      next++;
    }
    t++;
  }
  cout<<min<<' '<<level<<' '<<cnt<<'\n';
  return 0;
}