#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int x=1;
  cin>>s;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='A') {
      if(x==1) x=2;
      else if(x==2) x=1;
    } else if(s[i]=='B') {
      if(x==2) x=3;
      else if(x==3) x=2;
    } else {
      if(x==1) x=3;
      else if(x==3) x=1;
    }
  }
  cout<<x<<'\n';
  return 0;
}