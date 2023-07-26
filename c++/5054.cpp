#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, x, min, max;
  cin>>t;
  while(t--) {
    cin>>n;
    min=max=-1;
    for(int i=0; i<n; i++) {
      cin>>x;
      if(min<0 || min>x) min=x;
      if(max<0 || max<x) max=x;
    }
    cout<<(max-min)*2<<'\n';
  }
  return 0;
}