#include <iostream>
using namespace std;

int main() {
  int x, y, l, w;
  cin>>x>>y;
  y+=x; x=(x/2)+2;
  for(w=1; w<x; w++) {
    l=x-w;
    if(l*w==y) break;
  }
  cout<<l<<' '<<w<<'\n';
  return 0;
}