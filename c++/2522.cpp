#include <iostream>
using namespace std;

int main() {
  int n, a, b, k;
  cin>>n;
  a=1; b=n-1; k=1;
  for(int i=1; i<2*n; i++) {
    for(int j=0; j<b; j++) cout<<' ';
    for(int i=0; i<a; i++) cout<<'*';
    if(i==n) k=-1;
    a+=k; b-=k;
    cout<<'\n';
  }
  return 0;
}