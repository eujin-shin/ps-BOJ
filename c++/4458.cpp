#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int t;
  cin>>t;
  getline(cin, s);
  for(int i=0; i<t; i++) {
    getline(cin, s);
    if(s[0]>='a' && s[0]<='z') s[0]+=('A'-'a');
    cout<<s<<'\n';
  }
  return 0;
}