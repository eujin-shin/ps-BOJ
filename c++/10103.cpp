#include <iostream>
using namespace std;

int main() {
  int n, x=100, y=100, a, b;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a>>b;
    if(a<b) x-=b;
    else if(a>b) y-=a;
  }
  cout<<x<<'\n'<<y<<'\n';
  return 0;
}