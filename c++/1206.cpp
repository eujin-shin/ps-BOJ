#include <iostream>
using namespace std;

int MinK(double d) {
  int k=1;
  while(1) {
    if((int)(d*k)+1<(d+0.001)*k) break;
    if((int)(d*k)==d*k) break;
    k++;
  }
  return k;
}

int Gcd(int a, int b) {
  int tmp;
  if(a==b) return a;
  if(a<b) {
    tmp=a; a=b; b=tmp;
  }
  if(a%b==0) return b;
  return Gcd(b, a-b);
}

int main() {
  int n, x=1, tmp;
  double d;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>d;
    tmp=MinK(d);
    x=x*tmp/Gcd(x, tmp);
  }
  cout<<x<<'\n';
  return 0;
}