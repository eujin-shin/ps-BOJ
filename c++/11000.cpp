#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define M 200000
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, s, t, count=1;
  vector <pair<int, int> > v;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s>>t;
    v.push_back(make_pair(s, t));
  }
  sort(v.begin(), v.end());
  priority_queue <int, vector<int>, greater<int> > end;
  end.push(v[0].second);
  for(int i=1; i<n; i++) {
    if(end.top()<=v[i].first) {
      end.pop();
      end.push(v[i].second);
    } else {
      end.push(v[i].second);
      count++;
    }
  }
  cout<<count<<'\n';
  return 0;
}