#include <iostream>
using namespace std;

int main() {
  int n, f, p, a, b;
  cin>>n>>a>>b>>p;
  if(b-a==p-b) f=0; 
  else f=1;
  for(int i=3; i<n; i++) cin>>p;
  cout<<((f==0) ? (p+b-a) : (b/a*p))<<'\n';
  return 0;
}