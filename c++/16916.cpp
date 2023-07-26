#include <iostream>
#include <string>
using namespace std;

int Check(string p, string s, int idx) {
  int flag=1;
  for(int i=1; i<p.size(); i++) {
    if(p[i]==s[idx+i]) continue;
    flag=0; break;
  }
  return flag;
}

int main() {
  ios_base::sync_with_stdio(false);
  string p, s;
  int n, m, flag=0;
  cin>>s>>p;
  if(p.size()>s.size()) {
    cout<<"0\n"; return 0;
  }
  for(int i=0; i<=s.size()-p.size(); i++) {
    if(s[i]==p[0]) flag=Check(p, s, i);
    if(flag==1) break;
  }
  cout<<flag<<'\n';
  return 0;
}