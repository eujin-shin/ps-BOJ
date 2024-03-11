#include <iostream>
#include <vector>
#include <algorithm>
#define ppnt pair<int, pair<int, int> >
using namespace std;

vector <ppnt> v;
vector <int> dp;

int main() {
  ios_base::sync_with_stdio(false);
  int n, t, p, k=0, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>t>>p;
    v.push_back(make_pair(i+t, make_pair(t, p)));
  }
  sort(v.begin(), v.end());
  dp.push_back(0);
  for(int i=1; i<=n; i++) {
    dp.push_back(dp[i-1]);
    while(v[k].first<=i && k<n) {
      tmp=dp[i-v[k].second.first]+v[k].second.second;
      if(dp[i]<tmp) dp[i]=tmp;
      k++;
    }
  }
  cout<<dp[n]<<'\n';
  return 0;
}