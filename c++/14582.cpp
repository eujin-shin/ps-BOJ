#include <iostream>
using namespace std;

int main() {
  int a[9]={0, }, b[9]={0, }, x=0, y=0;
  bool f=false;
  for(int i=0; i<9; i++) cin>>a[i];
  for(int i=0; i<9; i++) {
    x+=a[i];
    if(x>y) f=true;
    cin>>b[i]; y+=b[i];
  }
  if(f) cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}