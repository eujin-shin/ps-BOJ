#include <iostream>
using namespace std;

int main() {
  int n, x, ans=-1, arr[51]={0, };
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; arr[x]++;
  }
  if(arr[0]==0) ans=0;
  for(int i=50; i>0; i--) {
    if(arr[i]!=i) continue;
    ans=i; break;
  }
  cout<<ans<<'\n';
  return 0;
}