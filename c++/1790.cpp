#include <iostream>
using namespace std;

int main() {
  int n, k, l=1, r=10, ans=-1;
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    if(i>=r) {
      r*=10; l++;
    }
    if(k<=l) {
      r=1;
      for(int j=0; j<l-k; j++) {
        r*=10;
      }
      i/=r; ans=i%10; break;
    } else {
      k-=l;
    }
  }
  cout<<ans<<'\n';
  return 0;
}