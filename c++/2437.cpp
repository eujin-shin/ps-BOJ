#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  int n, x, t=1;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; v.push_back(x);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++) {
    if(v[i]>t) break;
    t+=v[i];
  }
  cout<<t<<'\n';
  return 0;
}