#include <iostream>
#define ll long long
using namespace std;

ll Connect(ll a, ll b) {
  ll k=10;
  while(k<=b) k*=10;
  return a*k+b;
}

int main() {
  ll a, b, c, d, x, y;
  cin>>a>>b>>c>>d; 
  x=Connect(a, b); y=Connect(c, d);
  cout<<x+y<<'\n';
  return 0;
}