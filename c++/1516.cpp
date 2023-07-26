#include <iostream>
#include <vector>
#include <queue>
#define M 501
using namespace std;

vector <int> outd[M];
queue <int> q;
int t[M]={0, }, b[M]={0, }, ind[M]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, cur, next;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>t[i];
    cin>>x;
    while(x!=-1) {
      outd[x].push_back(i); ind[i]+=1;
      cin>>x;
    }
    if(ind[i]==0) q.push(i);
  }
  while(q.size()>=4) {
    cur=q.front(); q.pop();
    for(int i=0; i<outd[cur].size(); i++) {
      next=outd[cur][i];
      if(b[next]<t[cur]) b[next]=t[cur];
      ind[next]-=1;
      if(ind[next]==0) {
        t[next]+=b[next]; q.push(next);
      }
    }
  }
  for(int i=1; i<=n; i++) {
    cout<<t[i]<<'\n';
  }
  return 0;
}