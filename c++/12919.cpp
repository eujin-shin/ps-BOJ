#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int flag=0;

void Check(string t, string s) {
  if(t.size()==s.size()) {
    if(t.compare(s)==0) flag=1;
    return;
  }
  string tmp;
  if(t[t.size()-1]=='A') {
    tmp=t.substr(0, t.size()-1);
    Check(tmp, s);
  }
  if(flag) return;
  if(t[0]=='B') {
    tmp=t.substr(1, t.size()-1);
    reverse(tmp.begin(), tmp.end());
    Check(tmp, s);
  }
  return;
}

int main() {
  string t, s;
  cin>>s>>t;
  Check(t, s);
  cout<<flag<<'\n';
  return 0;
}