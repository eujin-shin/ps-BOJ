#include <iostream>
using namespace std;

int main() {
  int t, y, k, a, b;
  cin>>t;
  while(t--) {
    y=0; k=0;
    for(int i=0; i<9; i++) {
      cin>>a>>b;
      y+=a; k+=b;
    }
    if(k>y) cout<<"Korea\n";
    else if(y>k) cout<<"Yonsei\n";
    else cout<<"Draw\n";
  }
  return 0;
}