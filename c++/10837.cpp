#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k, c, m, n, x, y, tmp, flag;
  bool back;
  cin>>k>>c;
  for(int i=0; i<c; i++) {
    cin>>m>>n;
    if(n<m) {
      back=false; x=m; y=n;
    } else {
      back=true; x=n; y=m;
    }
    flag=1;
    for(int j=x-1; j>=y; j--) {
      tmp=k-j;
      if(back) tmp--;
      if(tmp>=j-y) continue;
      flag=0; break;
    }
    cout<<flag<<'\n';
  }
  return 0;
}