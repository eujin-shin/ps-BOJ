#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  int x, y, flag=0;
  cin>>a>>b;
  for(int i=0; i<a.size(); i++) {
    for(int j=0; j<b.size(); j++) {
      if(a[i]==b[j]) {
        x=i; y=j; flag=1; 
        break;
      }
    }
    if(flag) break;
  }
  for(int i=0; i<b.size(); i++) {
    for(int j=0; j<a.size(); j++) {
      if(i==y) cout<<a[j];
      else if(j==x) cout<<b[i];
      else cout<<'.';
    }
    cout<<'\n';
  }
  return 0;
}