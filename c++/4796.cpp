#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int l, p, v, x;
  for(int i=1; ; i++) {
    cin>>l>>p>>v;
    if(l+p+v==0) {
      break;
    }
    x = l*(v/p);
    if(v%p) {
      if(v%p<=l) {
        x += v%p;
      } else {
        x += l;
      }
    }
    cout<<"Case "<<i<<": "<<x<<'\n';
  }
  return 0;
}