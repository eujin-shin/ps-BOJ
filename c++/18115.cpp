#include <iostream>
#include <vector>
using namespace std;

vector <int> m, v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, l, r;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; m.push_back(x);
  }
  for(int i=n-1; i>=0; i--) {
    x=n-i;
    if(m[i]==1) v.insert(v.begin(), x);
    else if(m[i]==2) v.insert(v.begin()+1, x);
    else if(m[i]==3) v.push_back(x);
  }
  for(int i=0; i<n; i++) {
    cout<<v[i];
    if(i!=n-1) cout<<' ';
  }
  cout<<'\n';
  return 0;
}