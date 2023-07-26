#include <iostream>
using namespace std;

int main() {
  int l, r;
  cin>>l>>r;
  if(l==r) {
    if(l==0) cout<<"Not a moose\n";
    else cout<<"Even "<<l*2<<'\n';
  } else if(l>r) {
    cout<<"Odd "<<l*2<<'\n';
  } else {
    cout<<"Odd "<<r*2<<"\n";
  }
  return 0;
}