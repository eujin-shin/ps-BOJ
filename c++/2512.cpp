#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, tmp, left, count, sum=0, ans;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  cin>>m;
  count=n; left=m;
  for(int i=0; i<n; i++) {
    if(v[i]<=left/count) {
      left-=v[i]; count--;
    }
    sum+=v[i];
  }
  if(sum<=m) ans=v[n-1];
  else ans=left/count;
  cout<<ans<<'\n';
  return 0;
}