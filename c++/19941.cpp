#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> h, p;

int main() {
  string line;
  int n, k, cnt=0, j;
  cin>>n>>k;
  cin>>line;
  for(int i=1; i<=n; i++) {
    if(line[i-1]=='H') h.push_back(i);
    else p.push_back(i);
  }
  j=0;
  for(int i=0; i<h.size(); i++) {
    while(j<p.size() && h[i]-k>p[j]) j++;
    if(j>=p.size()) break;
    if(p[j]>=h[i]-k && p[j]<=h[i]+k) {
      cnt++; j++;
    }
  }
  cout<<cnt<<'\n';
  return 0;
}