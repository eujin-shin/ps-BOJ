#include <iostream>
using namespace std;

int main() {
  int l, r, c=9, b=1, count=0;
  cin>>l>>r;
  while(l) {
    if(l%10==8) {
      if(l/10*10*b+c*b>r) count++;
    }
    l/=10; b*=10;
  }
  cout<<count<<'\n';
  return 0;
}