#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    if(i%2) cout<<' ';
    for(int j=0; j<n; j++) {
      if(j>0) cout<<' ';
      cout<<'*';
    }
    cout<<'\n';
  }
  return 0;
}