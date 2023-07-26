#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  int n, x, tmp, ans=4;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++) {
    x=v[i]+4; tmp=4;
    for(int j=i+1; j<n && v[j]<=x; j++) {
      tmp--;
    }
    if(tmp<ans) ans=tmp;
  }
  cout<<ans<<'\n';
  return 0;
}