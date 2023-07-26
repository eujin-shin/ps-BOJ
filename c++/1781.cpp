#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pnt pair<int, int>
#define M 200001
using namespace std;

vector <int> v[M];

int main() {
  ios_base::sync_with_stdio(false);
  priority_queue <int> q;
  int n, a, b, sum=0, d;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a>>b;
    v[a].push_back(b);
  }
  for(int i=n; i>0; i--) {
    for(int j=0; j<v[i].size(); j++) q.push(v[i][j]);
    if(q.empty()) continue;
    sum+=q.top(); q.pop();
  }
  cout<<sum<<'\n';
  return 0;
}