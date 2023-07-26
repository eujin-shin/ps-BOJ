#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);  
  cin.tie(NULL);
  int t, c, a[4]={0, }, x[4]={25, 10, 5, 1};
  cin>>t;
  while(t--) {
    cin>>c;
    for(int i=0; i<4; i++) {
      cout<<c/x[i];
      if(i<3) cout<<' ';
      c%=x[i];
    }
    cout<<'\n';
  }
  return 0;
}