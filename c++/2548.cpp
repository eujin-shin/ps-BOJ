#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector <int> v;
  int n, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  if(n%2==0) n--;
  cout<<v[n/2]<<'\n';
  return 0;
}