#include <iostream>
using namespace std;

int main() {
  int n, c=1;
  cin>>n;
  for(int i=0; i<n; i++) c*=2;
  cout<<c<<'\n';
  return 0;
}