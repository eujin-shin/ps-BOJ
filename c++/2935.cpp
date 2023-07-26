#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  char op;
  int x, y, tmp;
  cin>>a>>op>>b;
  x=a.size(); y=b.size();
  if(op=='*') {
    cout<<'1';
    for(int i=0; i<x+y-2; i++) cout<<'0';
    cout<<'\n';
  } else {
    if(x<y) {
      tmp=x; x=y; y=tmp;
    }
    if(x!=y) cout<<'1';
    else cout<<'2';
    for(int i=0; i<x-1; i++) {
      if(i==x-y-1) cout<<'1';
      else cout<<'0';
    }
    cout<<'\n';
  }
  return 0;
}