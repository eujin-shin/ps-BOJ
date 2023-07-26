#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int a, b, n, k, sum=0;
  cin>>n>>k;
  cin>>a;
  for(int i=1; i<n; i++) {
    cin>>b; v.push_back(b-a); a=b;
  }
  sort(v.begin(), v.end());
  for(int i=0; n-i>k; i++) sum+=v[i];
  cout<<sum<<'\n';
  return 0;
}