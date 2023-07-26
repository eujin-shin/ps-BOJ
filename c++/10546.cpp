#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> a, b;

int main() {
  string tmp;
  int n, k;
  cin>>n;
  k=n-1;
  for(int i=0; i<n; i++) {
    cin>>tmp; a.push_back(tmp);
  }
  for(int i=0; i<n-1; i++) {
    cin>>tmp; b.push_back(tmp);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for(int i=0; i<n-1; i++) {
    if(a[i].compare(b[i])!=0) {
      k=i; break;
    }
  }
  cout<<a[k]<<'\n';
  return 0;
}