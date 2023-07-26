#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> s;
vector <int> l;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, pos, sum=0;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>pos;
    s.push_back(pos);
  }
  sort(s.begin(), s.end());
  for(int i=1; i<n; i++) {
    l.push_back(s[i]-s[i-1]);
  }
  sort(l.begin(), l.end());
  for(int i=0; i<n-k; i++) {
    sum+=l[i];
  }
  cout<<sum<<'\n';
  return 0;
}