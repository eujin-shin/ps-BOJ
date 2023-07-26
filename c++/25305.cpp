#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, tmp;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  cout<<v[n-k]<<'\n';
  return 0;
}