#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  cin>>n;
  a=1; b=n-1;
  for(int i=1; i<2*n; i++) {
    for(int j=0; j<b; j++) cout<<' ';
    for(int j=0; j<a; j++) cout<<'*';
    cout<<'\n';
    if(i<n) {
      a+=2; b--;
    } else {
      a-=2; b++;
    }
  }
  return 0;
}