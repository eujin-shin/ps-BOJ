#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp;
  long long sum=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for(int i=1; i<=n; i++) {
    sum+=abs(v[i-1]-i);
  }
  cout<<sum<<'\n';
  return 0;
}