#include <iostream>
using namespace std;

int main() {
  int n, t, x, s;
  s=0; x=0; cin>>n;
  for(int i=0; i<n; i++) {
    cin>>t;
    if(t==0) x=0;
    else s+=++x;
  }
  cout<<s<<'\n';
  return 0;
}