#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, cnt=0;
  string s;
  cin>>n>>s;
  for(int i=0; i<n-3; i++) {
    if(s[i]!='p') continue;
    if(s[i+1]=='P' && s[i+2]=='A' && s[i+3]=='p') {
      cnt++; i+=3;
    }
  }
  cout<<cnt<<'\n';
  return 0
  ;
}