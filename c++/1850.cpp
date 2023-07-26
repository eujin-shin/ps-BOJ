#include <iostream>
#define ll long long
using namespace std;

void Swap(ll *a, ll *b) {
  ll temp=*a;
  *a=*b; *b=temp;
  return;
}

ll Gcd(ll a, ll b) {
  if(a==b) return a;
  if(a<b) Swap(&a, &b);
  ll temp=a-b;
  if(b%temp==0) return temp;
  return Gcd(b, temp);
}

int main() {
  ll a, b, gcd;
  cin>>a>>b;
  gcd=Gcd(a, b);
  for(ll i=0; i<gcd; i++) {
    cout<<"1";
  }
  cout<<'\n';
  return 0;
}