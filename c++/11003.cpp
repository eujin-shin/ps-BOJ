#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

priority_queue <int, vector<int>, greater<int> > pq, out;
vector <int> v;
queue <int> q;

int main() {
  ios_base::sync_with_stdio(false);
  int n, l, tmp;
  cin>>n>>l;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    q.push(tmp); pq.push(tmp);
    while(q.size()>l) {
      out.push(q.front()); q.pop();
    }
    while(!out.empty() && out.top()==pq.top()) {
      out.pop(); pq.pop();
    }
    v.push_back(pq.top());
  }
  for(int i=0; i<v.size(); i++) {
    cout<<v[i];
    if(i==v.size()-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}