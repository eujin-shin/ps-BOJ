#include <iostream>
#include <math.h>
using namespace std;

double GetLen(int a, int b, int x, int y) {
  int m, n;
  m=(a-x)*(a-x); n=(b-y)*(b-y);
  return sqrt(m+n);
}

int main() {
  int x, y, w, h, p, a, b, c=0;
  cin>>w>>h>>x>>y>>p;
  for(int i=0; i<p; i++) {
    cin>>a>>b;
    if(a>=x && a<=x+w && b>=y && b<=y+h) c++;
    else if(GetLen(a, b, x, y+h/2)<=h/2) c++;
    else if(GetLen(a, b, x+w, y+h/2)<=h/2) c++;
  }
  cout<<c<<'\n';
  return 0;
}