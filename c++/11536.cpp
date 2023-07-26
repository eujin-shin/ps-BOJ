#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string a, b;
  bool flag=true, c;
  cin>>n>>a>>b;
  c=a>b; a=b;
  for(int i=2; i<n; i++) {
    cin>>b;
    if(c != a>b) flag=false;
    a=b;
  }
  if(!flag) cout<<"NEITHER\n";
  else if(c) cout<<"DECREASING\n";
  else cout<<"INCREASING\n";
  return 0;
}