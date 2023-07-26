#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, tmp;
  int n;
  cin>>n>>s;
  for(int i=1; i<n; i++) {
    cin>>tmp;
    for(int j=0; j<s.size(); j++) {
      if(s[j]!=tmp[j]) s[j]='?';
    }
  }
  cout<<s<<'\n';
  return 0;
}