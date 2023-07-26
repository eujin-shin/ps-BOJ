#include <iostream>
using namespace std;

int main() {
  int a=0, b=0, t;
  for(int i=3; i>0; i--) {
    cin>>t; a+=t*i;
  }
  for(int i=3; i>0; i--) {
    cin>>t; b+=t*i;
  }
  if(a>b) cout<<"A\n";
  else if(b>a) cout<<"B\n";
  else cout<<"T\n";
  return 0;
}