#include <iostream>
using namespace std;

int main() {
  int n, a, b, ans=-1;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a>>b;
    if(a>b) continue;
    if(ans<0 || b<ans) ans=b;
  }
  cout<<ans<<'\n';
  return 0;
}