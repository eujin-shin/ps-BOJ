#include <iostream>
#include <vector>
#include <algorithm>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, l, x, y, count, p, k;
  cin>>n>>l;
  for(int i=0; i<n; i++) {
    cin>>x>>y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  count=0; p=0;
  for(int i=0; i<n; i++) {
    x=v[i].first; y=v[i].second;
    if(y<p) continue;
    if(x>p) p=x;
    k=(y-p)/l;
    if((y-p)%l!=0) k++;
    p+=k*l; count+=k;
  }
  cout<<count<<'\n';
  return 0;
}