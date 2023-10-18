#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    for(int j=0; j<s.length(); j++) {
      if(s[j]>='A' && s[j]<='Z') s[j]=s[j]-'A'+'a';
    }
    cout<<s<<'\n';
  }
  return 0;
}