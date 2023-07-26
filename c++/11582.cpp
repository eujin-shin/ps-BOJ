#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp, k;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  cin>>k;
  for(int i=n/2; i>=1; i/=2) {
    for(int j=0; j<n; j+=n/i) {
      sort(v.begin()+j, v.begin()+j+n/i);
    }
    if(i==k) break;
  }
  for(int i=0; i<n; i++) {
    cout<<v[i];
    if(i!=n-1) cout<<' ';
  }
  cout<<'\n';
  return 0;
}