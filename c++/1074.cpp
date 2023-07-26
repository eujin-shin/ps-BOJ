#include <iostream>
using namespace std;

int Search(int x, int y, int l, int s) {
  int k, sum = 0;
  while(s>1) {
    s/=4;
    if(x<l/2 && y<l/2) {
      k = 0;
    } else if(y<l/2) {
      k = s;
      x -= l/2;
    } else if(x<l/2) {
      k = 2*s;
      y -= l/2;
    } else {
      k = 3*s;
      x -= l/2;
      y -= l/2;
    }
    sum += k;
    l/=2;
  }
  return sum;
}

int main() {
  int n, l=1, r, c, ans;
  cin>>n>>r>>c;
  for(int i=0; i<n; i++) {
    l*=2;
  }
  ans = Search(c, r, l, l*l);
  cout<<ans<<endl;
  return 0;
}