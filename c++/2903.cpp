#include <iostream>
using namespace std;

int main() {
  int n;
  long x=2;
  cin>>n;
  for(int i=0; i<n; i++) x+=x-1;
  cout<<x*x<<'\n';
  return 0;
}