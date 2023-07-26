#include <iostream>
using namespace std;

int main() {
  int n, x, y;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(n%2==0 && j==n-1) {
        break;
      } 
      if(j%2==0) {
        cout<<'*';
      } else {
        cout<<' ';
      }
    }
    cout<<'\n';
    for(int j=0; j<n; j++) {
      if(n%2 && j==n-1) {
        break;
      } 
      if(j%2) {
        cout<<'*';
      } else {
        cout<<' ';
      }
    }
    if(n>1) cout<<'\n';
  }
}