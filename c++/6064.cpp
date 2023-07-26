#include <iostream>
using namespace std;

int gcd(int a, int b) {
  int tmp;
  if(a<b) {
    tmp=b; b=a; a=tmp;
  } else if(a==b) {
    return a;
  }
  if(a%b==0) return b;
  return gcd(b, a-b);
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, x, y, m, n, g, l, ans;
  cin>>t;
  while(t--) {
    cin>>m>>n>>x>>y;
    ans=-1;
    g=gcd(m, n); l=m*n/g;
    for(int i=0; i*m+x<=l; i++) {
      if((i*m+x-y)%n==0) ans=i*m+x;
    }
    cout<<ans<<'\n';
  }
  return 0;
}