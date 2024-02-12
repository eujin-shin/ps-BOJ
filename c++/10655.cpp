#include <iostream>
#include <vector>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v;

int Dist(int i, int j) {
  int d=0, t;
  t=v[i].first-v[j].first;
  d+=(t<0 ? -t : t);
  t=v[i].second-v[j].second;
  d+=(t<0 ? -t : t);
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, y, a, b, d, sum=0, max=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x>>y;
    v.push_back(make_pair(x, y));
  }
  a=Dist(0, 1);
  for(int i=1; i<n-1; i++) {
    b=Dist(i, i+1);
    sum+=a;
    d=Dist(i-1, i+1);
    if(max<a+b-d) max=a+b-d;
    a=b;
  }
  cout<<sum+b-max<<'\n';
  return 0;
}