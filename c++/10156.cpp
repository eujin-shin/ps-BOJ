#include <iostream>
using namespace std;

int main() {
  int k, n, m, ans;
  cin>>k>>n>>m;
  ans=k*n-m;
  if(ans<0) ans=0;
  cout<<ans<<'\n';
  return 0;
}