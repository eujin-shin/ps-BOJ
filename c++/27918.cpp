#include <iostream>
using namespace std;

int main() {
  int n, d=0, p=0;
  char c;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>c;
    if(d+1<p || d>p+1) continue;
    if(c=='D') d++;
    else p++;
  }
  cout<<d<<':'<<p<<"\n";
  return 0;
}