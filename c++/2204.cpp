#include <iostream>
#include <string>
using namespace std;

string Check(string a, string b) {
  int x, y;
  for(int i=0; i<a.size(); i++) {
    if(i>=b.size()) return b;
    x=((a[i]>'Z') ? (a[i]-'a') : (a[i]-'A'));
    y=((b[i]>'Z') ? (b[i]-'a') : (b[i]-'A'));
    if(x>y) return b;
    else if(y>x) return a;
  }
  return a;
}

int main() {
  int n;
  string s, tmp;
  cin>>n;
  while(n>0) {
    cin>>s;
    for(int i=1; i<n; i++) {
      cin>>tmp;
      s=Check(s, tmp);
    }
    cout<<s<<'\n';
    cin>>n;
  }
  return 0;
}