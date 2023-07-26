#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> v;

void Sum(string l, string s) {
  int c=0, tmp;
  for(int i=1; i<=l.size(); i++) {
    tmp=l[l.size()-i]-'0'+c;
    if(i<=s.size()) tmp+=s[s.size()-i]-'0';
    if(tmp>9) {
      c=tmp/10; tmp=tmp%10;
    }
    else c=0;
    v.push_back(tmp);
  }
  if(c!=0) v.push_back(c);
  return;
}

int main() {
  string a, b;
  cin>>a>>b;
  if(a.size()>b.size()) Sum(a, b);
  else Sum(b, a);
  for(int i=1; i<=v.size(); i++) {
    cout<<v[v.size()-i];
  }
  cout<<'\n';
  return 0;
}