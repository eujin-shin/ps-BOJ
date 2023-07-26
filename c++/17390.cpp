#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q, tmp, l, r;
  v.push_back(0);
  cin>>n>>q;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for(int i=1; i<=n; i++) v[i]+=v[i-1];
  for(int i=0; i<q; i++) {
    cin>>l>>r;
    cout<<v[r]-v[l-1]<<'\n';
  }
  return 0;
}