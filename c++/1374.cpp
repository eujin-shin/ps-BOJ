#include <iostream>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int arr[100001][3]={0, };
priority_queue <pnt, vector<pnt>, greater<pnt> > s;
priority_queue <int, vector<int>, greater<int> > e;

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, cnt=0, a, b;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    cin>>arr[x][0]>>arr[x][1];
    s.push(make_pair(arr[x][0], arr[x][1]));
  }
  while(!s.empty()) {
    a=s.top().first; b=s.top().second;
    s.pop();
    while(!e.empty() && e.top()<=a) e.pop();
    e.push(b);
    if(cnt<e.size()) cnt=e.size();
  }
  cout<<cnt<<'\n';
  return 0;
}