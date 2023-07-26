#include <iostream>
using namespace std;

int main() {
  int n, x=1;
  cin>>n;
  while(x<=n) {
    for(int i=0; i<n-x; i++) cout<<' ';
    for(int i=0; i<x; i++) {
      if(i>0) cout<<' ';
      cout<<'*';
    }
    cout<<'\n';
    x++;
  }
  return 0;
}