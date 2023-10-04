#include <iostream>
using namespace std;

int s[1000000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, o, x, r=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>o;
    if(o==1) {
      cin>>x; s[r++]=x;
    } else if(o==2) {
      if(0<r) cout<<s[--r]<<'\n';
      else cout<<"-1\n";
    } else if(o==3) {
      cout<<r<<'\n';
    } else if(o==4) {
      if(0<r) cout<<"0\n";
      else cout<<"1\n";
    } else if(o==5) {
      if(0<r) cout<<s[r-1]<<'\n';
      else cout<<"-1\n";
    }
  }
  return 0;
}