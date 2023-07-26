#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t, n, max, r, tmp, m, d, sum;
  cin>>t;
  while(t--) {
    cin>>n;
    max=0; sum=0;
    for(int i=0; i<n; i++) {
      cin>>tmp; sum+=tmp;
      if(max>tmp) continue;
      if(max<tmp) {
        d=0; max=tmp; r=i+1;
      } else {
        d=1;
      }
    }
    if(d) cout<<"no winner\n";
    else {
      if(sum/2<max) cout<<"majority winner ";
      else cout<<"minority winner ";
      cout<<r<<'\n';
    }
  }
  return 0;
}