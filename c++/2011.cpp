#include <iostream>
#include <string>
#define M 1000000
using namespace std;

int main() {
  string s;
  int a=1, b=0, tmp;
  cin>>s;
  for(int i=1; i<s.size(); i++) {
    if(s[i]=='0') {
      if(s[i-1]=='1' || s[i-1]=='2') {
        b=a; a=0;
      } else {
        a=0; b=0; break;
      }
    } else if(s[i-1]=='1') {
      tmp=a; a+=b; b=tmp;
    } else if(s[i-1]=='2' && s[i]<='6') {
      tmp=a; a+=b; b=tmp;
    } else {
      a+=b; b=0;
    }
    a%=M;
  }
  if(s[0]=='0') {
    a=0; b=0;
  }
  cout<<(a+b)%M<<'\n';
}