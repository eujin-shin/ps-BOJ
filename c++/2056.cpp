#include <iostream>
#include <vector>
#include <queue>
#define M 10001
using namespace std;

int main() {
  int time[M]={0, }, ind[M]={0, }, before[M]={0, };
  vector <int> outd[M];
  queue <int> q;
  int n, k, x, cur, next, max=0;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>time[i]>>ind[i];
    if(ind[i]==0) {
      q.push(i);
      if(max<time[i]) max=time[i];
    } for(int j=0; j<ind[i]; j++) {
      cin>>x;
      outd[x].push_back(i);
    }
  }
  while(!q.empty()) {
    cur=q.front(); q.pop();
    for(int i=0; i<outd[cur].size(); i++) {
      next=outd[cur][i];
      if(before[next]<time[cur]) before[next]=time[cur];
      ind[next]-=1;
      if(ind[next]!=0) continue;
      time[next]+=before[next]; q.push(next);
      if(time[next]>max) max=time[next];
    }
  }
  cout<<max<<'\n';
  return 0;
}