#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector <int> a, b, c;
  int n, m, tmp;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tmp; a.push_back(tmp);
  }
  for(int i=0; i<m; i++) {
    cin>>tmp; b.push_back(tmp);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  tmp=0;
  for(int i=0; i<n; i++) {
    while(tmp<b.size() && b[tmp]<a[i]) tmp++;
    if(tmp>=b.size() || b[tmp]>a[i]) {
      c.push_back(a[i]);
    }
  }
  cout<<c.size()<<'\n';
  for(int i=0; i<c.size(); i++) {
    cout<<c[i];
    if(i<c.size()-1) cout<<' ';
    else cout<<'\n';
  }
  return 0;
}