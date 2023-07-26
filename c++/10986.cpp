#include <iostream>
using namespace std;

int psum[1001]={0, };

int main() {
  long long ans=0;
  int n, m, x, s=0;
  cin>>n>>m;
  psum[0]=1;
  for(int i=0; i<n; i++) {
    cin>>x; s=(s+x)%m;
    ans+=psum[s]; psum[s]+=1;
  }
  cout<<ans<<'\n';
  return 0;
}