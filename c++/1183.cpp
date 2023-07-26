#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

int main() {
  int n, a, b, k;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a>>b;
    v.push_back(a-b);
  }
  if(n%2==1) {
    k=1;
  } else {
    sort(v.begin(), v.end());
    k=v[n/2]-v[n/2-1]+1;
  }
  cout<<k<<'\n';
  return 0;
}