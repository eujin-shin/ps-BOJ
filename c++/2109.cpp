#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define M 10001
using namespace std;

vector <int> v[M];

int main() {
  ios_base::sync_with_stdio(false);
  int n, p, d, md=0, top, s, sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>p>>d;
    if(md<d) md=d;
    v[d].push_back(p);
  }
  priority_queue <int, vector<int>, greater<int> > pq;
  for(int i=1; i<=md; i++) {
    s=v[i].size();
    if(s==0) continue;
    sort(v[i].begin(), v[i].end());
    for(int j=s-1; j>=0; j--) {
      if(pq.size()<i) {
        sum+=v[i][j]; pq.push(v[i][j]); continue;
      }
      top=pq.top();
      if(top>v[i][j]) break;
      sum=sum-top+v[i][j]; pq.pop(); pq.push(v[i][j]);
    }
  }
  cout<<sum<<'\n';
  return 0;
}